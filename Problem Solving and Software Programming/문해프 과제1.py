price = {'커피':3500, '라떼':4000, '스무디':4500, '차':3000}
menu = []       #사용자가 주문한 메뉴를 저장하는 리스트
money = 0       #사용자가 내야 할 금액을 저장하는 변수 

print("==========MENU=========")    #메뉴 보여주는 print문 
print("=  커피   :   3,500원 =")
print("=  라떼   :   4,000원 =")
print("=  스무디 :   4,500원 =")
print("=  차     :   3,000원 =")
print("=  '끝' 입력 시 종료  =")
print("=======================\n")

while(1):                           #메뉴 입력받기 위한 while문
    choice = input("원하시는 메뉴를 입력해주세요 : ")
    if choice in price:             #만약 price(메뉴판) 안에 choice(메뉴)이 있다면
        menu.append(choice)             #menu에 사용자가 선택한 메뉴명을 넣는다
        money += price[choice]          #money에 사용자가 낼 금액을 누적해서 더한다 
    elif choice == "끝":            #만약 사용자가 끝<<을 입력한다면
        break                           #무한루프를 벗어난다!
    else :                          #이것들이 아니라면 (= 메뉴판 외의 것이 입력된다면)
        print("    !! 메뉴에 있는 음료가 아닙니다. 다시 입력해주세요. !!")

print("")
for i in range(len(menu)):          #리스트 menu에 저장된 음료 이름을 순서대로 프린트
    print(menu[i], end=", ")        #뒤에 end=", "를 붙임으로써 줄바꿈 안되고 ',' 붙음

print("총", str(len(menu))+"개의 음료 주문 시에 결제 금액은",str(money)+"원 입니다.")

