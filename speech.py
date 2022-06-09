import speech_recognition as sr
from gtts import gTTS
import os
from playsound import playsound

r = sr.Recognizer()

lan = "en"
with sr.Microphone() as source:
    r.adjust_for_ambient_noise(source, duration=1)
    print('speak something....')
    
    audio = r.listen(source)
try:
    text = r.recognize_google(audio)
    #text = r.recognize_google(audio, language="ja-JP")
    print ('you said:  {}'.format(text))
   # print(text = r.recognize_google(audio))
except:
    print("couldnt recognize voice")
if (text=="hello"): text="hi usama how are you"
if (text=="お前はもう死んでいる"): text = "Naaaaaaaani"
if (text == "how are you"):text ="i am fine how are you"
if (text =="sing me a song"): playsound("sample.mp3")
if (text =="wish her"): text="happy birthday skidal baji"
output = gTTS(text,lang=lan, slow = False )
#if (text=="お前はもう死んでいる"): print("i say:  Naanniiiiii!!!")
output.save("out.mp3")
playsound("out.mp3")