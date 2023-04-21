#import opencv
import cv2
#import the library deepface
from deepface import DeepFace
import serial

# create serial object named arduino
arduino = serial.Serial('/dev/cu.usbmodem14201', 9600) 
face_cascade = cv2.CascadeClassifier('/Users/ivaniovine/Desktop/research_hfg/python_machine_learning/deepface/emotion_recognition_deepface_arduino/haarcascade_frontalface_default.xml')


cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    result = DeepFace.analyze(img_path = frame, actions=['emotion'], enforce_detection=False)

    gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(gray,1.1,4)

    for(x,y,w,h) in faces:
        cv2.rectangle(frame,(x,y),(x+w, y+h), (0,0,255), 5)
    
    #show dominant emotion
    emotion = result['dominant_emotion']
    #display the emotion
    txt = str(emotion)
    cv2.putText(frame, txt, (50,50), cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,255),5)

    #send data to arduino
    if emotion == 'happy':
        servo_degree = str(180)
        arduino.write(servo_degree.encode())
    elif emotion == 'sad' or emotion == 'angry':
        servo_degree = str(0)
        arduino.write(servo_degree.encode())
    else :
        servo_degree = str(90)
        arduino.write(servo_degree.encode())

    #show frames
    cv2.imshow('frame', frame)

    if cv2.waitKey(1) & 0xff == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()