/* document.write("Hello World! (document.write)");
console.log("Hello World! (console.log)");
alert("Hello World! (alert)");
prompt("Enter your name: (prompt)");
confirm("Are you sure? (confirm)");

let a = 10; 
console.log(typeof(a)); // number

var b; // not recommended
console.log(typeof(b)); // undefined

let c = Number('string');
console.log(c); // NaN
console.log(typeof(c)); // number

let name = prompt("Enter your name: ");
let age = +prompt("Enter your age: ");

alert("Your name is " + name + " and your age is " + age + " years old."); // not recommended
alert("After 10 years your age will be " + (age + 10) +" years old."); // not recommended

alert(`Your name is ${name} and your age is ${age} years old.`);
alert('2'+2); // 22

let number = prompt("Enter first number:");
let number2 = prompt("Enter second number");

alert(+number + +number2);

if(number > number2){
    alert(`${number} is greater than ${number2}`);
}
else if(number < number2){
    alert(`${number2} is greater than ${number}`);
}
else{
    alert(`${number} is equal to ${number2}`);
}

let choice = +prompt("Enter your choice: \n1. Addition \n2. Subtraction\n3. Multiplication\n4. Division")
switch  (choice)
{
    case 1:
        alert(`Addition of ${number} and ${number2} is ${number + number2}`);
        break;
    case 2:
        alert(`Subtraction of ${number} and ${number2} is ${number - number2}`);
        break;  
    case 3:
        alert(`Multiplication of ${number} and ${number2} is ${number * number2}`);
        break;
        default:
        alert(`Division of ${number} and ${number2} is ${number / number2}`);
        break;
}

let str = ' ';
for(let i = 1; i <= 10; i++) {
    str += i + ' ';
} console.log(str);

let num = 10;
while(num >0) {
    console.log(num);
    num--;
} do {
    let name = prompt("Enter your name: ");
    console.log(name);
} while (name !='' && name != null);

function getName(a, c,d, f){
    let name = prompt ("Enter your name : ");
    return name;
}

let name = getName('h', 'l', 'j', 'k');
console.log(name); */



// 1
// let name = prompt("Введіть своє їм'я: ");
// alert(`Привіт ${name}!`)

// 2
// let age = prompt("Введіть свій вік: ");
// let age2 = prompt("У вас був день народження у цьому році? (1 - ні; 0 - так)");
// alert("Ти народився у " + (2024 - age2 - age) +" році.");

// 3
// let side = prompt("Введіть довжину сторони квадрата: ");
// alert("Периметр квадрата " + (side * 4) + ".");

// 4
// let radius = prompt("Введіть радіус кола: ");
// alert("Площа кола = " + (3.14 * radius * 2) + ".");

// 5
// let distance = prompt("Відстань у кілометрах між двома містами: ");
// let time = prompt("За скільки годин ти хочеш дістатися: ");
// alert("Швидкість, з якою потрібно рухатися, щоб встигнути вчасно = " + (distance/time) + "км на годину.");

// 6
// const USD = 39.65;
// let uah = prompt("Введіть долари, програма конвертує їх у гривні: ");
// alert("Ваші долари у гривняі123х: "+(uah*USD) + ".");

// 7
// const GB = 1024; 
// let fDrive = prompt("Введи обсяг флешки у ГБ: ");
// alert((fDrive * GB / 820) + " файлів розміром 820 МБ вміститься на флешку.");

// 8
// let sum = prompt("Введи суму грошей у гаманці: ");
// let price = prompt("Введи вартість шоколадки: ");
// let choco = (sum - sum % price) / price, surrender = sum - choco * price;
// alert(`${choco} шоколадок можете купити і ${surrender} здачі у вас залишиться.`);

// 9
// let number = prompt("Введи тризначне число: ");
// let num1 = number % 10;
// let num2 = ((number - num1) / 10) % 10;
// let num3 = (number - num1 - num2 * 10) / 100;
// let palindrome = num1 * 100 + num2 * 10 + num3;
// alert(`Паліндром числа ${number} це ${palindrome}`);

// 10
let number = prompt("Введіть ціле число:");
let result = (number % 2 == 0) ? "парне" : "непарне";
alert("Ваше число " + result + "!");
