from recognition import FaceTracking
# pip install cmake dlib==19.22

if __name__ == '__main__':
    fr = FaceTracking()
    fr.run_tracking()