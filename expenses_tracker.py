#!/usr/local/bin/python

import json
import os.path
import datetime


month = datetime.datetime.now().strftime("%B") #current month (worded)


class INITILIZE(): #creates neccessery .json files
    def __init__(self):
        self.expenses = dict()
        self.current_sum = dict()
        
        print(f"The program must create new files for this month: {month}")
        
        
        cat = input("What is your first expense? (category name): ")
        value = float(input("What is the sum worth?: "))
        
        self.expenses[cat] = value #assigning first category and its value
        
        with open(f"{month}_expenses.json", "w") as outfile2:
            json.dump(self.expenses, outfile2, indent=4) #creates file with user's input
            
        inp = float(input("\n\nWhat is the sum on your account at the moment? (after the expense): "))
        
        self.current_sum["current_sum"] = inp
        
        with open(f"current_sum{month}.json", "w") as outfile1: #creates file with user's input
            json.dump(self.current_sum, outfile1, indent=4)
        
        
        print("\n\nFiles for this month created!")

        APP(); #calls the App class
        

class APP():
    def __init__(self):
        with open(f"{month}_expenses.json", 'r') as file: #loads .json file into the program
            self.data = json.load(file)
            self.kat_dict = self.data
            
        with open(f"current_sum{month}.json", 'r') as ffile: #loads .json file into the program
            self.data_sum = json.load(ffile)
            self.current_sum = float(self.data_sum["current_sum"])
            
                    
        cnt = 1 #counter
        choices = ["ADD AN EXPENSE", "EXIT"]
        print(f"""\n\nCurrently you have: {self.current_sum} PLN\n
Your expenses so far:\n""")

        for cat in self.kat_dict: #prints categories and spending until this point. The currency is in PLN
            print(f"{cat} : {self.kat_dict[cat]} PLN") 
        
        print("\n\nWhat do you want to do now? Here are your choices: \n")
        for choice in choices:
            print(f"{cnt}. {choice}")
            cnt += 1
        
        print("\n")
        inp = input()
      
        if inp == "1":
            self.add_expense();
        
        
        elif inp == "2":
            self.exit();
            
        else:
            print("You must choose correct number!")
            self.__init__(); #try again if you fail to input correct number


    def add_cat(self, category): #add category passed from add_expense function
        self.new_category = category 
        self.kat_dict[self.new_category] = self.expense #add spendings value
        with open(f'{month}_expenses.json', 'r+') as file3: #and save
            json.dump(self.kat_dict, file3, indent = 8)
        self.__init__(); #what do you want to do now?

    
    def add_expense(self): #add new expense
        try: #if you fail to use correct float format
            self.expense = float(input("Expense worth: "));
        except:
            print("You must type in a correct sum: XX.XXX")
            self.add_expense();
            
        self.current_sum -= self.expense #update current sum
        self.data_sum["current_sum"] = self.current_sum
        
        with open(f'current_sum{month}.json', 'r+') as file2: #update current sum in the file
            json.dump(self.data_sum, file2, indent = 4)        
        
        self.category = input("CATEGORY: ")
        if self.category in self.kat_dict: #if category already exists
            self.kat_dict[self.category] += self.expense
            with open(f'{month}_expenses.json', 'r+') as file2:
                json.dump(self.kat_dict, file2, indent = 8)
            print("\nExpense added!\n")
            self.__init__();
            
        else: #if category does not exist
            print("This category does not exist. Do you want to add it? (Y/N)")
            if input().upper() == "Y":
                self.add_cat(self.category);
            elif input().upper() == "N":
                self.__init__();
                
                
    def exit(self):
        print("\nADIOS!")
        exit();
        


if os.path.isfile(f"{month}_expenses.json"): #checks if neccessery files exist
    APP();
else:
    INITILIZE();
            