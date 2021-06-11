
import numpy as np
import cv2 as cv
cap=cv.VideoCapture(1) #seleccionar webcam
def nothing(x):
    pass
cv.namedWindow('VALORES')
cv.createTrackbar('Hue Minimo','VALORES',0,255,nothing)
cv.createTrackbar('Hue Maximo','VALORES',0,255,nothing)
cv.createTrackbar('Sat. Minima','VALORES',0,255,nothing)
cv.createTrackbar('Sat. Maximo','VALORES',0,255,nothing)
cv.createTrackbar('Value Minimo','VALORES',0,255,nothing)
cv.createTrackbar('value Maximo','VALORES',0,255,nothing)
while(True):
    ret, frame=cap.read() #informacion de la camara
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    H_MIN = cv.getTrackbarPos('Hue Minimo', 'VALORES')
    H_MAX = cv.getTrackbarPos('Hue Maximo', 'VALORES')
    S_MIN = cv.getTrackbarPos('Sat. Minima', 'VALORES')
    S_MAX = cv.getTrackbarPos('Sat. Maximo', 'VALORES')
    V_MIN = cv.getTrackbarPos('Value Minimo', 'VALORES')
    V_MAX = cv.getTrackbarPos('value Maximo', 'VALORES')
    lower = np.array([H_MIN, S_MIN, V_MIN])
    upper = np.array([H_MAX, S_MAX, V_MAX])
    mask = cv.inRange(hsv, lower, upper)

    kernel = np.ones((3, 3), np.uint8)
    erosion=cv.erode(mask,kernel,iterations=4)
    dilation = cv.dilate(erosion, kernel, iterations=4)
    x, y, w, h = cv.boundingRect(dilation)
    cv.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 5)
    print(x + w / 2, y + h / 2)
    font = cv.FONT_HERSHEY_SIMPLEX
    cv.putText(frame, "(x:" + str(x + round(w / 2)) + ",y:" + str(y + round(h / 2)) + ")",
               (x + round(w / 2) - 60, y + round(h / 2)), font, 1, (255, 0, 0), 2, cv.LINE_AA)

    cv.imshow('rest', frame)
    cv.imshow('maska', dilation)
    if cv.waitKey(1) & 0xFF==27:
        break
cap.release()
cv.destroyAllWindows()
