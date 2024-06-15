class Circle {
    constructor(radius) {
        this.radius = radius;
    }
    get getRadius() {
        return this.radius;
    }
    set setRadius(radius) {
        this.radius = radius;
    }
    get getDiameter() {
        return this.radius * 2;
    }
    
    calculateArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }
    calculateCircumference() {
        return 2 * Math.PI * this.radius;
    }
}

let myCircle = new Circle(5);
console.log("Радіус кола:", myCircle.getRadius);
myCircle.setRadius = 10;
console.log("Новий радіус кола:", myCircle.getRadius);
console.log("Діаметр кола:", myCircle.getDiameter);
console.log("Площа кола:", myCircle.calculateArea());
console.log("Довжина кола:", myCircle.calculateCircumference());
