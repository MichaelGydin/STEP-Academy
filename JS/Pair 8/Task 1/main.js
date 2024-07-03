const images = [
    "images/image1.jpg",
    "images/image2.jpg",
    "images/image3.jpg",
    "images/image4.jpg",
    "images/image5.jpg",
    "images/image6.jpg"
];

let currentImageIndex = 0;

const prevBtn = document.getElementById("prevBtn");
const nextBtn = document.getElementById("nextBtn");
const galleryImage = document.getElementById("galleryImage");

function showPrevImage() {
    currentImageIndex--;
    if (currentImageIndex < 0) {
        currentImageIndex = 0;
    }
    galleryImage.src = images[currentImageIndex];
    updateButtonState();
}

function showNextImage() {
    currentImageIndex++;
    if (currentImageIndex >= images.length) {
        currentImageIndex = images.length - 1;
    }
    galleryImage.src = images[currentImageIndex];
    updateButtonState();
}

function updateButtonState() {
    prevBtn.disabled = (currentImageIndex === 0);
    nextBtn.disabled = (currentImageIndex === images.length - 1);
}

galleryImage.src = images[currentImageIndex];
updateButtonState();
