#Read maximum storage capacity of the port
C = float(input())

#Read number of containers
N = int(input())

total = 0
heaviest = 0
lightest = 0

#Read weight of each container
for i in range(N):
    weight = float(input())

    #Calculate total shipment weight
    total += weight

    #Initialize heaviest and lightest using first container
    if i == 0:
        heaviest = weight
        lightest = weight

    #Find heaviest container
    if weight > heaviest:
        heaviest = weight

    #Find lightest container
    if weight < lightest:
        lightest = weight

#Calculate average container weight
average = total / N

print("Total Shipment Weight:", total)
print("Average Container Weight:", average)
print("Heaviest Container:", heaviest)
print("Lightest Container:", lightest)

#Classification is Heavy if total >= 200, otherwise Light
if total >= 200:
    print("Classification: Heavy")
else:
    print("Classification: Light")

#Print port capacity
print("Port Capacity:", C)

#Check if shipment can be unloaded
if total <= C:
    print("Status: Shipment can be unloaded")
else:
    print("Status: Shipment exceeds port capacity")
