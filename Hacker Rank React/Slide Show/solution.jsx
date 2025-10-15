import React, { useState } from "react";

function Slides({ slides }) {
  ''''This portion implemented by me
  const[currIndex,setCurrIndex]=useState(0);
  const handleNext=()=>{
    if(currIndex<slides.length-1){
    setCurrIndex(prev=>prev+1);
  }
}
  const handlePrev=()=>{
    if(currIndex>0){
    setCurrIndex(prev=>prev-1);
    }
  }
  const handleRestart=()=>{
    setCurrIndex(0);
  }
  ''''''
  return (
    <div>
      <div id="navigation" className="text-center">
          <button
          data-testid="button-restart"
          className="small outlined"
          onClick={handleRestart}
          disabled={currIndex === 0}
        >
          Restart
        </button>

        <button
          data-testid="button-prev"
          className="small"
          onClick={handlePrev}
          disabled={currIndex === 0}
        >
          Prev
        </button>

        <button
          data-testid="button-next"
          className="small"
          onClick={handleNext}
          disabled={currIndex === slides.length - 1}
        >
          Next
        </button>
      </div>

      <div id="slide" className="card text-center">
        <h1 data-testid="title">{slides[currIndex].title}</h1>
        <p data-testid="text">{slides[currIndex].text}</p>
      </div>
    </div>
  );
}

export default Slides;
