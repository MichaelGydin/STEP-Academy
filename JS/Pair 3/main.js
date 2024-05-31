// task 1
class Marker {
    constructor(color, inkPercentage) {
        this.color = color;
        this.inkPercentage = inkPercentage;
    }

    print(text) {
        let inkRequired = text.replace(/\s/g, "").length * 0.5;
        if (inkRequired > this.inkPercentage) {
            console.log("Not enough ink to print the text.");
            return;
        }

        let printedText = "";
        for (let char of text) {
            if (char !== " ") {
                if (this.inkPercentage >= 0.5) {
                    printedText += char;
                    this.inkPercentage -= 0.5;
                } else {
                    break;
                }
            } else {
                printedText += " ";
            }
        }
        console.log(`Printed text: ${printedText}`);
    }
}

class RMarker extends Marker {
    constructor(color, inkPercentage, capacity) {
        super(color, inkPercentage);
        this.capacity = capacity;
    }

    refill() {
        this.inkPercentage = this.capacity;
        console.log("Marker refilled.");
    }
}

let marker = new Marker("blue", 50);
marker.print("Hello, world!");

let rMarker = new RMarker("red", 20, 100);
rMarker.print("Lorem ipsum dolor sit amet");
rMarker.refill();
rMarker.print("Lorem ipsum dolor sit amet");

// task 2
class ExtendedDate extends Date {
    constructor(...args) {
        super(...args);
    }

    getFormattedDate() {
        const months = [
            "січня", "лютого", "березня",
            "квітня", "травня", "червня",
            "липня", "серпня", "вересня",
            "жовтня", "листопада", "грудня"
        ];
        return `${this.getDate()} ${months[this.getMonth()]}`;
    }

    isFutureOrCurrentDate() {
        return this.getTime() >= Date.now();
    }

    isLeapYear() {
        const year = this.getFullYear();
        return (year % 4 === 0 && year % 100 !== 0) || (year % 400 === 0);
    }

    getNextDate() {
        const nextDay = new Date(this);
        nextDay.setDate(this.getDate() + 1);
        return nextDay;
    }
}

const date = new ExtendedDate();
console.log(`Formatted Date: ${date.getFormattedDate()}`);
console.log(`Is Future or Current Date: ${date.isFutureOrCurrentDate()}`);
console.log(`Is Leap Year: ${date.isLeapYear()}`);
console.log(`Next Date: ${date.getNextDate().toLocaleDateString()}`);

// task 3
class Employee {
    constructor(name, position) {
        this.name = name;
        this.position = position;
    }
}

class EmpTable {
    constructor(employees) {
        this.employees = employees;
    }

    getHtml() {
        let tableHtml = '<table><tr><th>Name</th><th>Position</th></tr>';
        this.employees.forEach(employee => {
            tableHtml += `<tr><td>${employee.name}</td><td>${employee.position}</td></tr>`;
        });
        tableHtml += '</table>';
        return tableHtml;
    }
}

let employees = [
    new Employee('John Doe', 'Manager'),
    new Employee('Jane Smith', 'Accountant'),
    new Employee('Alice Johnson', 'Teller')
];

let empTable = new EmpTable(employees);
document.body.innerHTML = empTable.getHtml();

// task 4
class StyledEmpTable extends EmpTable {
    getStyles() {
        return '<style>table { border-collapse: collapse; width: 100%; } th, td { border: 1px solid black; padding: 8px; text-align: left; }</style>';
    }

    getHtml() {
        return this.getStyles() + super.getHtml();
    }
}

let styledEmpTable = new StyledEmpTable(employees);
document.body.innerHTML = styledEmpTable.getHtml();
