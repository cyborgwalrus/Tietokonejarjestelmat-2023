def kertolasku(num1, num2):
    # initialize variables
    bitmask = 0b1
    output = 0
    remaining = num2
    bitshift_counter = 0
    while(remaining != 0):
        # read bit using bitmask
        variable = num2
        variable = bitmask & variable
        if(variable != 0):
            # bitshift num1 and add it to output
            bitshift_input = num1
            bitshift_output = bitshift_input << bitshift_counter
            output = bitshift_output + output
            remaining = bitmask ^ remaining
        
        # increment bitmask and counter
        bitshift_counter += 1
        bitmask = bitmask + bitmask

        print(f"num1: {num1}, num2:{num2}")

    return output

if __name__ == "__main__":
    for i in range(1,100):
        for j in range(1,100):
            assert(kertolasku(i,j) == i*j)