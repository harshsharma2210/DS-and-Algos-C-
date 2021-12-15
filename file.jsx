import React, { useState } from "react";
import "./Home.css";
import Menu from "./filter";
import GalleryReact from "./GalleryReact";

function Home() {
  const GalleryReact = () => {
    const [items, setItems] = useState(Menu);
  };
  return items.map((elem) => {
    const { id, image, description, price, name } = elem;
    return (
      <>
        <h2>PORTFOLIO</h2>

        <div class="column nature">
          <div class="content">
            <img className="img-fluid" src={image} alt="Lights" />
            <h4>{name}</h4>
            <p>{description}</p>
          </div>
        </div>
      </>
    );
  });
}

export default Home;
