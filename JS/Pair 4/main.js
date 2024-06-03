// task 1
// class PrintMachine {
//     constructor(fontSize, fontColor, fontFamily) {
//         this.fontSize = fontSize;
//         this.fontColor = fontColor;
// this.fontFamily = fontFamily;
//     }

//     print(text) {
//         document.write(`<p style="font-size: ${this.fontSize}px; color: ${this.fontColor}; font-family: ${this.fontFamily};">${text}</p>`);
//     }
// }

// const pm = new PrintMachine(14, 'red', 'Arial');
// pm.print('Hello, world!');

// task 2
// class News {
//     constructor(title, text, tags, publicationDate) {
//         this.title = title;
//         this.text = text;
//         this.tags = tags;
//         this.publicationDate = publicationDate;
//     }

//     print() {
//         const now = new Date();
//         const diffMs = now - new Date(this.publicationDate);
//         const diffDays = Math.floor(diffMs / (1000 * 60 * 60 * 24));

//         let dateString;
//         if (diffDays < 1) {
//             dateString = "сьогодні";
//         } else if (diffDays < 7) {
//             dateString = `${diffDays} днів тому`;
//         } else {
//             const dateParts = this.publicationDate.split('-');
//             dateString = `${dateParts[2]}.${dateParts[1]}.${dateParts[0]}`;
//         }

//         console.log(`Заголовок: ${this.title}\nТекст: ${this.text}\nТеги: ${this.tags.join(', ')}\nДата публікації: ${dateString}`);
//     }
// }

// const myNews = new News("ТСН", "Приклад тексту.", ["тег1", "тег2"], "2009-10-29");
// myNews.print();

// task 3
class News {
    constructor(title, text, tags, publicationDate) {
        this.title = title;
        this.text = text;
        this.tags = tags;
        this.publicationDate = publicationDate;
    }

    print() {
        console.log(`Заголовок: ${this.title}`);
        console.log(`Текст: ${this.text}`);
        console.log(`Теги: ${this.tags.join(', ')}`);
        console.log(`Дата публікації: ${this.publicationDate}`);
    }
}

class NewsTape {
    constructor() {
        this.news = [];
    }

    get newsCount() {
        return this.news.length;
    }

    printNews() {
        this.news.forEach(news => {
            news.print();
            console.log("-----------------------------------");
        });
    }

    addNews(title, text, tags, publicationDate) {
        const newNews = new News(title, text, tags, publicationDate);
        this.news.push(newNews);
    }

    removeNews(index) {
        if (index >= 0 && index < this.news.length) {
            this.news.splice(index, 1);
        } else {
            console.log("Помилка");
        }
    }

    sortNewsByDate() {
        this.news.sort((a, b) => {
            const aDate = new Date(a.publicationDate);
            const bDate = new Date(b.publicationDate);
            return bDate - aDate;
        });
    }

    findNewsByTag(tag) {
        const foundNews = this.news.filter(news => news.tags.includes(tag));
        return foundNews;
    }
}

const newsTape = new NewsTape();

newsTape.addNews("Важливі Новини 1", "Приклад тексту 1.", ["тег11", "тег12"], "2001-01-01");
newsTape.addNews("Важливі Новини 2", "Приклад тексту 2.", ["тег21", "тег22"], "2002-02-02");
newsTape.addNews("Важливі Новини 3", "Приклад тексту 3.", ["тег31", "тег32"], "2003-03-03");

console.log(`Кількість новин: ${newsTape.newsCount}`);

newsTape.printNews();

newsTape.sortNewsByDate();
console.log("Новини, відсортовані за датою:");
newsTape.printNews();

const foundNews = newsTape.findNewsByTag("тег11");
console.log("Новини за тегом 'тег11':");
foundNews.forEach(news => {
    news.print();
    console.log("-----------------------------------");
});

newsTape.removeNews(1);
console.log("Новини після видалення 1:");
newsTape.printNews();