import React from 'react';

function BackgroundSettings({ bgColor, setBgColor, imageUrl, setImageUrl }) {
    return (
        <div>
            <label>
                Background Color:
                <input type="color" value={bgColor} onChange={(e) => setBgColor(e.target.value)} />
            </label>
            <label>
                Image URL:
                <input type="text" value={imageUrl} onChange={(e) => setImageUrl(e.target.value)} />
            </label>
        </div>
    );
}

export default BackgroundSettings;
