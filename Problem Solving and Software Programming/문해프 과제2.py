import tkinter as tk        #tkinter 모듈을 불러옴 (tk라 부르기로 함)

price = {'커피':3500, '라떼':4000, '스무디':4500, '차':3000}
menu = []                   #사용자가 주문한 메뉴를 저장하는 리스트
money = 0                   #사용자가 내야 할 금액을 보여주는 변수

def coffee():               #커피 주문 시 실행되는 함수
    global money                #money를 전역변수로 선언
    menu.append("커피")         #menu에 사용자가 주문한 '커피' 넣음
    money += price["커피"]      #money에 사용자가 내야 할 금액을 누적해서 더함

def latte():                #라떼 주문 시 실행되는 함수
    global money
    menu.append("라떼")
    money += price["라떼"]

def smoothie():             #스무디 주문 시 실행되는 함수
    global money
    menu.append("스무디")
    money += price["스무디"]

def tea():                  #차 주문 시 실행되는 함수
    global money
    menu.append("차")
    money += price["차"]

def finish():               #'주문완료' 버튼을 누르면 실행되는 함수
    global money
    
    #label의 text를 변경하는 방식 사용
    l2.config(text="총 금액 : %d 원" %money)    #이때까지 누적한 금액 출력
    l3.config(text=menu)    #이때까지 주문한 메뉴 출력(리스트)
    money = 0               #화면에 가격 띄우며 누적금액 0으로 초기화
    menu.clear()            #화면에 메뉴 띄우며 메뉴를 빈 리스트로 초기화
    


w = tk.Tk()     #창 생성

# w라는 공간에, text라는 글을 띄우는 label 생성   //너비, 높이, 배경색, 폰트색 추가로 지정
# (1,1)의 공간에 배치
l1 = tk.Label(w, text="[ 메뉴를 선택해주세요 ]",width=20,height=2,bg='dark green', fg='white')
l1.grid(row=1, column=1)

# w라는 공간에, text라는 이름의 버튼 생성. 버튼 누르면 command로 연결된 함수 실행됨
b1 = tk.Button(w, text="커피 : 3,500원", command=coffee, width=20)
b2 = tk.Button(w, text="라떼 : 4,000원", command=latte, width=20)
b3 = tk.Button(w, text="스무디 : 4,500원", command=smoothie, width=20)
b4 = tk.Button(w, text="차 : 3,000원", command=tea, width=20)
b5 = tk.Button(w, text="주문 완료", command=finish, width=20, bg='green', fg='white')

# 버튼들 (n,1)의 공간에 배치
b1.grid(row=2, column=1)
b2.grid(row=3, column=1)
b3.grid(row=4, column=1)
b4.grid(row=5, column=1)
b5.grid(row=6, column=1)

# w라는 공간에, '총 금액 :'이라는 라벨 띄우기
# 'finish()' 함수 실행 시, '총 금액 : @@@원'으로 text 바뀜
l2 = tk.Label(w, text="총 금액 :")
l2.grid(row=7, column=1, sticky='W')        # sticky='W' : West(서쪽)으로 정렬

# 'finish()' 함수 실행 시, 주문한 메뉴 나열되는 라벨 (처음에는 빈칸)
l3 = tk.Label(w)
l3.grid(row=8, column=1, sticky='W')

w.mainloop()
