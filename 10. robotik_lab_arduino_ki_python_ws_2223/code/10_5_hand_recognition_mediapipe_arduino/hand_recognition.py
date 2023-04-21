#import opencv
import cv2
#import the library mediapipe
import mediapipe as mp
#import pyserial library for serial communication
import serial 

#import dependencies
import numpy as np
import uuid 
import os


# create serial object named arduino
arduino = serial.Serial('/dev/cu.usbmodem14201', 9600) 

#set drawing and detection capabilities offered by mediapipe
mp_drawing = mp.solutions.drawing_utils
mp_hands = mp.solutions.hands

#define capture openCV istance
cap = cv2.VideoCapture(0)
with mp_hands.Hands(min_detection_confidence=0.8, min_tracking_confidence=0.5) as hands:
    while True:
        ret, frame = cap.read()
        
        #change color codes of the frame
        image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        #set flag
        image.flags.writeable = False

        #detect hands
        results = hands.process(image)

        #back to BGR
        image.flags.writeable = True
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        #prints results
        #print(results.multi_hand_landmarks)

        #render points and connections
        if results.multi_hand_landmarks:
            for num, hand in enumerate(results.multi_hand_landmarks):
                mp_drawing.draw_landmarks(image, hand, mp_hands.HAND_CONNECTIONS) 
                #calculate the distance between the first landmark middle finger and the wrist
                #print(float(results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.WRIST].y) - float(results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP].y))
                distance = results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.WRIST].y - results.multi_hand_landmarks[0].landmark[mp_hands.HandLandmark.MIDDLE_FINGER_TIP].y
                if distance < 0.2:
                    degree = str(0)
                    arduino.write(degree.encode())
                else:
                    degree = str(180)
                    arduino.write(degree.encode())
            
                image = cv2.putText(image, str(distance), (50,50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2, cv2.LINE_AA)

        cv2.imshow('Hand Tracking', image)

        if cv2.waitKey(1) & 0xff == ord('q'):
            break

cap.release()
cv2.destroyAllWindows()
