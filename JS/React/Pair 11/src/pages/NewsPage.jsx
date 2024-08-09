import React from 'react';
import './NewsPage.css';

function NewsPage() {
  return (
    <div className="news-page">
      <h1>Latest News</h1>
      <div className="news-item">
        <h2>News Title 1</h2>
        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
      </div>
      <div className="news-item">
        <h2>News Title 2</h2>
        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
      </div>
    </div>
  );
}

export default NewsPage;
