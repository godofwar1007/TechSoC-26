capacity = 0
weights = []

while True:
    print("\n1. Enter Shipment")
    print("2. Print Shipment Report")
    print("3. Display Sorted Containers")
    print("4. Draw Bar Chart")
    print("5. Save Report To File")
    print("6. Read Shipment From File")
    print("7. Search Container By Weight")
    print("8. Find Kth Heaviest Container")
    print("9. Exit")

    choice = int(input("Enter choice: "))

    if choice == 1:
        # Read maximum port capacity
        capacity = float(input("Enter port capacity: "))

        # Read number of containers
        n = int(input("Enter number of containers: "))

        weights.clear()

        # Read weight of each container
        for i in range(n):
            w = float(input("Enter weight of container " + str(i + 1) + ": "))
            weights.append(w)

    elif choice == 2:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            total = 0
            heaviest = weights[0]
            lightest = weights[0]

            # Calculate total, heaviest, and lightest container
            for w in weights:
                total += w

                if w > heaviest:
                    heaviest = w

                if w < lightest:
                    lightest = w

            # Calculate average container weight
            average = total / len(weights)

            print("Total Shipment Weight:", total)
            print("Average Container Weight:", average)
            print("Heaviest Container:", heaviest)
            print("Lightest Container:", lightest)

            # Classify shipment as Heavy if total >= 200, otherwise Light
            if total >= 200:
                print("Classification: Heavy")
            else:
                print("Classification: Light")

            # Display port capacity
            print("Port Capacity:", capacity)

            # Check whether shipment can be unloaded
            if total <= capacity:
                print("Status: Shipment can be unloaded")
            else:
                print("Status: Shipment exceeds port capacity")

    elif choice == 3:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            sorted_weights = weights.copy()

            # Display sorted container weights without using sort()
            for i in range(len(sorted_weights)):
                for j in range(len(sorted_weights) - 1):
                    if sorted_weights[j] > sorted_weights[j + 1]:
                        temp = sorted_weights[j]
                        sorted_weights[j] = sorted_weights[j + 1]
                        sorted_weights[j + 1] = temp

            print("Sorted Container Weights:")
            for w in sorted_weights:
                print(w)

    elif choice == 4:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            # Draw simple bar chart using *
            for i in range(len(weights)):
                print("Container", i + 1, ":", end=" ")

                stars = int(weights[i] / 5)

                for j in range(stars):
                    print("*", end="")

                print()

    elif choice == 5:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            filename = input("Enter file name: ")

            total = 0
            heaviest = weights[0]
            lightest = weights[0]

            # Calculate report data before saving
            for w in weights:
                total += w

                if w > heaviest:
                    heaviest = w

                if w < lightest:
                    lightest = w

            average = total / len(weights)

            # Save shipment report to a file
            file = open(filename, "w")

            file.write("Total Shipment Weight: " + str(total) + "\n")
            file.write("Average Container Weight: " + str(average) + "\n")
            file.write("Heaviest Container: " + str(heaviest) + "\n")
            file.write("Lightest Container: " + str(lightest) + "\n")

            if total >= 200:
                file.write("Classification: Heavy\n")
            else:
                file.write("Classification: Light\n")

            file.write("Port Capacity: " + str(capacity) + "\n")

            if total <= capacity:
                file.write("Status: Shipment can be unloaded\n")
            else:
                file.write("Status: Shipment exceeds port capacity\n")

            file.close()

            print("Report saved.")

    elif choice == 6:
        filename = input("Enter file name: ")

        try:
            file = open(filename, "r")

            # Read shipment data from a file
            # File format:
            # capacity
            # number_of_containers
            # weights...
            capacity = float(file.readline())
            n = int(file.readline())

            weights.clear()

            for i in range(n):
                w = float(file.readline())
                weights.append(w)

            file.close()

            print("Shipment data loaded.")

        except:
            print("File could not be opened.")

    elif choice == 7:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            target = float(input("Enter weight to search: "))
            found = False

            # Search for a specific container by weight
            for i in range(len(weights)):
                if weights[i] == target:
                    print("Container", i + 1, "has weight", target)
                    found = True

            if found == False:
                print("No container found with this weight.")

    elif choice == 8:
        if len(weights) == 0:
            print("No shipment data available.")
        else:
            k = int(input("Enter k: "))

            if k < 1 or k > len(weights):
                print("Invalid k.")
            else:
                sorted_weights = weights.copy()

                # Sort manually without using sort()
                for i in range(len(sorted_weights)):
                    for j in range(len(sorted_weights) - 1):
                        if sorted_weights[j] > sorted_weights[j + 1]:
                            temp = sorted_weights[j]
                            sorted_weights[j] = sorted_weights[j + 1]
                            sorted_weights[j + 1] = temp

                # Find Kth heaviest container
                kth = sorted_weights[len(sorted_weights) - k]

                print(k, "th heaviest container:", kth)

    elif choice == 9:
        break

    else:
        print("Invalid choice.")
