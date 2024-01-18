import LoadingScreen from "./LoadingScreen";
import { useState } from "react";

const Food = ({ onNext, id }) => {
    const [loading, setLoading] = useState(false);
    function handleSubmit(event) {
        console.log("5");
        id = id.userId;
        event.preventDefault();
        let fruitVegetablesNuts = event.target.fruitVegetablesNuts.value;
        let dairyProducts = event.target.dairyProducts.value;
        let chickenMeat = event.target.chickenMeat.value;
        let porkMeat = event.target.porkMeat.value;
        let beefMeat = event.target.beefMeat.value;
        let fish = event.target.fish.value;
        if (porkMeat === '' || porkMeat < 0) {
            porkMeat = 0;
        }
        if (beefMeat === '' || beefMeat < 0) {
            beefMeat = 0;
        }
        if (fish === '' || fish < 0) {
            fish = 0;
        }
        if (dairyProducts === '' || dairyProducts < 0) {
            dairyProducts = 0;
        }
        if (chickenMeat === '' || chickenMeat < 0) {
            chickenMeat = 0;
        }
        if (fruitVegetablesNuts === '' || fruitVegetablesNuts < 0) {
            fruitVegetablesNuts = 0;
        }
        setLoading(true);
        fetch("http://localhost:18080/food?id="+id+"&foods="+fruitVegetablesNuts+","+dairyProducts+","+porkMeat+","+chickenMeat+","+beefMeat+","+fish)
        .then(data => {
            setLoading(false);
            onNext();
        });
    }

    return (
        loading ? (<LoadingScreen />) : (
        <div className="formular">
            <form onSubmit={handleSubmit}>
                <h1>Food Carbon Footprint</h1>
                <div className='question-group'>
                    <label>Please provide information about your eating habits</label>
                    <p>Fruit, vegetables, nuts</p>
                    <input type='number' name='fruitVegetablesNuts' placeholder='kg per month' min="0"/>
                    <p>Dairy products</p>
                    <input type='number' name='dairyProducts' placeholder='kg per month' min="0"/>
                    <p>Chicken meat</p>
                    <input type='number' name='chickenMeat' placeholder='kg per month' min="0"/>
                    <p>Pork meat</p>
                    <input type='number' name='porkMeat' placeholder='kg per month' min="0"/>
                    <p>Beef meat</p>
                    <input type='number' name='beefMeat' placeholder='kg per month' min="0"/>
                    <p>Fish</p>
                    <input type='number' name='fish' placeholder='kg per month' min="0"/>
                </div>
                <button type="submit">Submit</button>
            </form>
        </div>
        )
    );
};

export default Food;