import React from 'react';

function LayoutSettings({ titlePosition, setTitlePosition, imagePosition, setImagePosition }) {
    return (
        <div>
            <label>
                Title Position:
                <select value={titlePosition} onChange={(e) => setTitlePosition(e.target.value)}>
                    <option value="left">Left</option>
                    <option value="center">Center</option>
                    <option value="right">Right</option>
                </select>
            </label>
            <label>
                Image Position:
                <select value={imagePosition} onChange={(e) => setImagePosition(e.target.value)}>
                    <option value="left">Left</option>
                    <option value="right">Right</option>
                </select>
            </label>
        </div>
    );
}

export default LayoutSettings;
