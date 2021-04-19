#Goal of this file is to get the URL to be passed and played in main file

import os
from dotenv import load_dotenv
import googleapiclient.discovery
import googleapiclient.errors
import random

from oauth2client import client # Added
from oauth2client import tools # Added
from oauth2client.file import Storage # Added

scopes = ["https://www.googleapis.com/auth/youtube.readonly"]
load_dotenv()
url_list = []
os.environ["OAUTHLIB_INSECURE_TRANSPORT"] = "0"
api_service_name = "youtube"
api_version = "v3"
client_secrets_file = os.getenv("client_secrets_file")

def get_url():
    credential_path = os.path.join('./', 'credential_sample.json')
    store = Storage(credential_path)
    credentials = store.get()
    if not credentials or credentials.invalid: #Simplifies authentication process so it doesn't need to be done every time
        flow = client.flow_from_clientsecrets(client_secrets_file, scopes)
        credentials = tools.run_flow(flow, store)
    youtube = googleapiclient.discovery.build(
        api_service_name, api_version, credentials=credentials)


    request = youtube.videos().list(
        part="id",
        myRating="like",
        maxResults=50,
        pageToken="CDIQAA"
    )
    response = request.execute() #gets response from API
    
    lst = response["items"]
    for x in range(49):
        url_list.append(lst[x]['id']) #creates a list of video IDs only
    
    return "https://www.youtube.com/watch?v=" + random.choice(url_list)
    

if __name__ == "__main__":
    get_url()