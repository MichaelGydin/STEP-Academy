import React, { useState } from 'react';
import Navbar from '../components/Navbar';
import ArticleComponent from '../components/ArticleComponent';
import FontSettings from '../components/FontSettings';
import BackgroundSettings from '../components/BackgroundSettings';
import LayoutSettings from '../components/LayoutSettings';
import './MainPage.css';

function MainPage() {
    const [title, setTitle] = useState('Назва статті');
    const [author, setAuthor] = useState('Автор');
    const [text, setText] = useState('Текст статті');
    const [date, setDate] = useState('Дата видання');

    const [fontFamily, setFontFamily] = useState('Arial');
    const [color, setColor] = useState('#000000');
    const [size, setSize] = useState('16px');

    const [bgColor, setBgColor] = useState('#ffffff');
    const [imageUrl, setImageUrl] = useState('');

    const [titlePosition, setTitlePosition] = useState('left');
    const [imagePosition, setImagePosition] = useState('left');

    const fontSettings = { fontFamily, color, size };
    const layoutSettings = { titlePosition, imagePosition };

    return (
        <>
            <Navbar />
            <div className="main-content">
                <FontSettings fontFamily={fontFamily} setFontFamily={setFontFamily} color={color} setColor={setColor} size={size} setSize={setSize} />
                <BackgroundSettings bgColor={bgColor} setBgColor={setBgColor} imageUrl={imageUrl} setImageUrl={setImageUrl} />
                <LayoutSettings titlePosition={titlePosition} setTitlePosition={setTitlePosition} imagePosition={imagePosition} setImagePosition={setImagePosition} />
                <ArticleComponent 
                    title={title} 
                    author={author} 
                    text={text} 
                    date={date} 
                    fontSettings={fontSettings} 
                    bgColor={bgColor} 
                    imageUrl={imageUrl} 
                    layoutSettings={layoutSettings} 
                />
            </div>
        </>
    );
}

export default MainPage;
