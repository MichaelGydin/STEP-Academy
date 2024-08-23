import React from 'react';

function FontSettings({ fontFamily, setFontFamily, color, setColor, size, setSize }) {
    return (
        <div>
            <label>
                Font Family:
                <input type="text" value={fontFamily} onChange={(e) => setFontFamily(e.target.value)} />
            </label>
            <label>
                Color:
                <input type="color" value={color} onChange={(e) => setColor(e.target.value)} />
            </label>
            <label>
                Size:
                <input type="number" value={size} onChange={(e) => setSize(e.target.value)} />
            </label>
        </div>
    );
}

export default FontSettings;
