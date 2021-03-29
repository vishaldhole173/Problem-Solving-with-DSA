import speech_recognition as sr
import webbrowser
import os
print("welcome to the new assistant\n\n")

print("Please your requirements............. we are listening.....", end="")
r=sr.Recognizer()

with sr.Microphone() as source:
     print('start saying..')
     audio=r.listen(source)
     print("we go it, plzzzz wait")
ch=r.recognize_google(audio)

if("date" in ch) and (("run" in ch) or ("execute" in ch)):
  os.system('date')
elif("time" in ch) and (("run" in ch) or ("execute" in ch)):
      os.system('time')
elif("calendar" in ch) and (("run" in ch) or ("execute" in ch) or ("open" in ch)):
  webbrowser.open("http://192.168.225.168/cgi-bin/iiec.py?x=cal")
elif("ifconfig" in ch) and (("run" in ch) or ("execute" in ch) or ("open" in ch)):
  webbrowser.open("http://192.168.225.168/cgi-bin/iiec.py?x=ifconfig")
elif(("OS" in ch) or ("new OS")) and (("run" in ch) or ("execute" in ch) or ("open" in ch)):
  webbrowser.open("http://192.168.225.125/p.html")  
else:
  print("sorry cannot recognise")