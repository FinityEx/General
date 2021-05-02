"""Console currency converter using Polish National Bank's API and PLN as base for conversions
Date of production: 2.05.2021
Last changes: 2.05.2021"""


import requests


resp = requests.get("http://api.nbp.pl/api/exchangerates/tables/a/") #get currency conversion table from PNB's API
dictionary_codes = resp.json()[0]['rates'] #parse result into more accesible dictionary of codes

print("Currency codes available: ")
for element in dictionary_codes:
    print(element["code"], end=" ") #print all currency 3-letter codes available


class App():
    def __init__(self):
        self.valueFromPLN = float
        self.valueToPLN = float
        self.result = float
        App.convert(self)


    def convert(self):     
        self.amount = float(input("\n\nWhat's the amount to be converted?: "))
        self.cur_from = input("From: ").upper() #from currency
        self.cur_to = input("To: ").upper() #to currency
        
      
        if self.cur_from == "PLN": #as PLN is a base currency, valueFromPLN needs to be set to 1.0 in this case
           self.valueFromPLN = 1.0
        else:
            for element in dictionary_codes: #search dictionary keys for input code
                if self.cur_from == element["code"]:
                    self.valueFromPLN = element["mid"] #if found, set valueFromPLN to value from dictionary
                    break
        
        if self.cur_to == "PLN": #PLN is a base currency
            self.valueToPLN = 1.0
        else:        
            for element in dictionary_codes:
                if self.cur_to == element["code"]:
                    self.valueToPLN = element["mid"]
                    break

        try:
            self.result = (self.amount * self.valueFromPLN) / self.valueToPLN
            print(f"\n{self.amount} {self.cur_from} = {self.result: .3f} {self.cur_to}") #prints calculated result
            
            self.rate_from = self.valueFromPLN / self.valueToPLN #prints conversion rate
            print(f"1 {self.cur_from} = {self.rate_from: .3f} {self.cur_to}") 
                        
            self.rate_to = self.valueToPLN / self.valueFromPLN #prints conversion rate
            print(f"1 {self.cur_to} = {self.rate_to: .3f} {self.cur_from}")
            
        except:
            print("One of the chosen codes is incorrect!") #prints if code hadn't been found in dictionary
        
        
if __name__ == "__main__":
    App()