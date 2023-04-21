import face_recognition
import os, sys
import cv2
import numpy as np
import math
import serial

# create serial object named arduino
arduino = serial.Serial('/dev/cu.usbmodem14201', 9600) 

class FaceTracking:
    face_locations = []
    face_encodings = []
    process_current_frame = True

    def run_tracking(self):
        video_capture = cv2.VideoCapture(0)

        if not video_capture.isOpened():
            sys.exit('Video source not found...')

        while True:
            ret, frame = video_capture.read()

            # Only process every other frame of video to save time
            if self.process_current_frame:
                # Resize frame of video to 1/4 size for faster face recognition processing
                small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)

                # Convert the image from BGR color (which OpenCV uses) to RGB color (which face_recognition uses)
                rgb_small_frame = small_frame[:, :, ::-1]

                # Find all the faces and face encodings in the current frame of video
                self.face_locations = face_recognition.face_locations(rgb_small_frame)
                self.face_encodings = face_recognition.face_encodings(rgb_small_frame, self.face_locations)

            self.process_current_frame = not self.process_current_frame

            # Display the results
            for (top, right, bottom, left) in self.face_locations:
                # Scale back up face locations since the frame we detected in was scaled to 1/4 size
                top *= 4
                right *= 4
                bottom *= 4
                left *= 4

               # Create the frame with the name
                cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)
                #print(left)
                cx = int((left + right)/2) 
                cy = int((top + bottom)/2)          
                cv2.circle(frame, (cx,cy), 20, (255, 0, 255))
                print(left)
                command = str(cx)
                arduino.write(command.encode())    
                
            # Display the resulting image
            cv2.imshow('Face Recognition', frame)

            # Hit 'q' on the keyboard to quit!
            if cv2.waitKey(1) == ord('q'):
                break

        # Release handle to the webcam
        video_capture.release()
        cv2.destroyAllWindows()


if __name__ == '__main__':
    fr = FaceTracking()
    fr.run_tracking()