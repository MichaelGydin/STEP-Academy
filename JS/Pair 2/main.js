// task 1
let car = {
    manufacturer: "Tesla",
    model: "Model S",
    year: 2023,
    averageSpeed: 100,

    showInfo: function() {
        console.log(`Manufacturer: ${this.manufacturer}, Model: ${this.model}, Year: ${this.year}, Average Speed: ${this.averageSpeed} km/h`);
    },

    calculateTime: function(distance) {
        let time = distance / this.averageSpeed;
        let restCount = Math.floor(time / 4);
        let totalTime = time + restCount;
        return totalTime;
    }
};

car.showInfo();
console.log(`Time to travel 400 km: ${car.calculateTime(400)} hours`);

// task 2
let fraction1 = {
    numerator: 1,
    denominator: 2
};

let fraction2 = {
    numerator: 1,
    denominator: 3
};

function addFractions(fraction1, fraction2) {
    let numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
    let denominator = fraction1.denominator * fraction2.denominator;
    return simplifyFraction({numerator, denominator});
}

function subtractFractions(fraction1, fraction2) {
    let numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
    let denominator = fraction1.denominator * fraction2.denominator;
    return simplifyFraction({numerator, denominator});
}

function multiplyFractions(fraction1, fraction2) {
    let numerator = fraction1.numerator * fraction2.numerator;
    let denominator = fraction1.denominator * fraction2.denominator;
    return simplifyFraction({numerator, denominator});
}

function divideFractions(fraction1, fraction2) {
    let numerator = fraction1.numerator * fraction2.denominator;
    let denominator = fraction1.denominator * fraction2.numerator;
    return simplifyFraction({numerator, denominator});
}

function simplifyFraction(fraction) {
    let gcd = (a, b) => (b === 0 ? a : gcd(b, a % b));
    let divisor = gcd(fraction.numerator, fraction.denominator);
    return {
        numerator: fraction.numerator / divisor,
        denominator: fraction.denominator / divisor
    };
}

console.log("Addition:", addFractions(fraction1, fraction2));
console.log("Subtraction:", subtractFractions(fraction1, fraction2));
console.log("Multiplication:", multiplyFractions(fraction1, fraction2));
console.log("Division:", divideFractions(fraction1, fraction2));

// task 3
let time = {
    hours: 0,
    minutes: 0,
    seconds: 0,

    showTime: function() {
        console.log(`Time: ${this.hours}:${this.minutes}:${this.seconds}`);
    },

    changeSeconds: function(seconds) {
        let totalSeconds = this.hours * 3600 + this.minutes * 60 + this.seconds + seconds;
        this.hours = Math.floor(totalSeconds / 3600) % 24;
        this.minutes = Math.floor((totalSeconds % 3600) / 60);
        this.seconds = totalSeconds % 60;
    },

    changeMinutes: function(minutes) {
        this.changeSeconds(minutes * 60);
    },

    changeHours: function(hours) {
        this.changeSeconds(hours * 3600);
    }
};

time.showTime();
time.changeSeconds(30);
time.showTime();
time.changeMinutes(2);
time.showTime();
time.changeHours(5);
time.showTime();
