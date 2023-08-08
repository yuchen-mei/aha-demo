import json 

with open("tile1/bin/design_meta.json") as file: 
  data = json.load(file)

with open("output.json", "w") as file:
  json.dump(data, file, indent=4)
