let lastClickedIndex = null;

document.addEventListener('DOMContentLoaded', () => {
    const bookItems = document.querySelectorAll('#bookList ol li');
    bookItems.forEach((item, index) => {
        item.addEventListener('click', (event) => handleBookClick(event, index));
    });
});

function handleBookClick(event, index) {
    const bookItems = document.querySelectorAll('#bookList ol li');

    if (!event.ctrlKey && !event.shiftKey) {
        bookItems.forEach(item => item.classList.remove('selected'));
    }

    if (event.ctrlKey) {
        bookItems[index].classList.toggle('selected');
    } else if (event.shiftKey && lastClickedIndex !== null) {
        const start = Math.min(lastClickedIndex, index);
        const end = Math.max(lastClickedIndex, index);
        for (let i = start; i <= end; i++) {
            bookItems[i].classList.add('selected');
        }
    } else {
        bookItems[index].classList.add('selected');
    }

    lastClickedIndex = index;
}
