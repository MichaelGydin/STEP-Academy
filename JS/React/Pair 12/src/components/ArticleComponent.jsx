import React from 'react';

function ArticleComponent({ title, author, text, date, fontSettings, bgColor, imageUrl, layoutSettings }) {
    const articleStyle = {
        backgroundColor: bgColor,
        fontFamily: fontSettings.fontFamily,
        color: fontSettings.color,
        fontSize: fontSettings.size,
        display: 'flex',
        flexDirection: layoutSettings.imagePosition === 'left' ? 'row' : 'row-reverse',
        alignItems: 'center',
        padding: '20px',
        borderRadius: '8px',
    };

    const imageStyle = {
        margin: layoutSettings.imagePosition === 'left' ? '0 20px 0 0' : '0 0 0 20px',
        width: '200px',
        height: 'auto',
    };

    return (
        <div style={articleStyle}>
            {imageUrl && <img src={imageUrl} alt="Article" style={imageStyle} />}
            <div>
                <h1 style={{ textAlign: layoutSettings.titlePosition }}>{title}</h1>
                <h3>{author}</h3>
                <p>{text}</p>
                <small>{date}</small>
            </div>
        </div>
    );
}

export default ArticleComponent;
