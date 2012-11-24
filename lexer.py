

#  lexer.py 




import string 

def findtype(str): 
   if isalpha(str[0]) or str[0] == '_': 
      toktype = "kw_colname"
   elif str[0] == '"': 
      toktype = "string" 
   elif isdigit(str[0]):  
      toktype = "integer" 
   elif str[0] == ',':
      toktype = "comma" 
   elif str[0] == ';': 
      toktype = "semicolon" 
   elif str[0] == '=': 
      toktype = "equals"                              
   else: 
      toktype = "other" 
      
      
      




