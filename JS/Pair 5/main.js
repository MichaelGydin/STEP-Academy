// task 1
let year = prompt("Введіть рік:");
let month = prompt("Введіть місяць:");
let day = prompt("Введіть день:");

let date = new Date(year, month - 1, day);

let options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
let formattedDate = date.toLocaleDateString('uk-UA', options);

alert(`Повна інформація про дату: ${formattedDate}`);

// task 2
let flashDriveSizeGB = prompt("Введіть обсяг флешки у ГБ:");
const fileSizeMB = 820;
const flashDriveSizeMB = flashDriveSizeGB * 1024;
let numberOfFiles = Math.floor(flashDriveSizeMB / fileSizeMB);

alert(`На флешку вміститься ${numberOfFiles} файлів розміром 820 МБ.`);

// task 3
let r = prompt("Введіть значення червоного (r):");
let g = prompt("Введіть значення зеленого (g):");
let b = prompt("Введіть значення синього (b):");

alert(`rgb(${r}, ${g}, ${b})`);

// task 4
let arr = [];
for (let i = 0; i < 10; i++) {
    arr.push(Math.floor(Math.random() * 21) - 10);
}

let newArr = arr.map(num => -num);
newArr.sort((a, b) => a - b);

console.log("Оригінальний масив:", arr);
console.log("Новий масив:", newArr);
