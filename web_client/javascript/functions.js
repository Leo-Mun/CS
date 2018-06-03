console.log("hello homework3")

function stringToInt(input) {
    return parseInt(input);
}

function maskNumber(input) {
    var mask_number = String(input);
    mask_number = mask_number.substr(0, 6);
    mask_number = mask_number.concat("****");

    return mask_number;
}

function getAverage(input_array) {
    var sum = 0;
    for (var i = 0; i < input_array.length; i++) {
        sum += input_array[i];
    }
    
    var average = 0;
    average = parseFloat(average);
    
    average = sum / input_array.length;
    
    return average;
}

function isMultipleSeven(input) {
    if (input % 7 == 0) {
        return true;
    }
    else {
        return false;
    }
}

function operation(type, a, b) {
    if (type === "add") {
        return a + b;
    }
    else if (type === "subtract") {
        return a - b;
    }
    
    else if (type === "multiply") {
        return a * b;
    } 
    
    else if (type === "divide") {
        return a / b;
    }
    
    else {
        console.log("Not Supported");
        return "undefined variable"
    }
}


function triangleMtn(floor) {
    var output = "";
    for (var i = 0; i < floor; i++ ) 
    {
        for (var j = 0; j <= i; j++ )
        {
            output += "*";
        }
        output += "\n";
    }
    console.log(output);


}
