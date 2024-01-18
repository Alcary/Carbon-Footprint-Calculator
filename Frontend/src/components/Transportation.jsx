import LoadingScreen from "./LoadingScreen";
import { useState } from "react";

const Transportation = ({ onNext, id }) => {
  const [loading, setLoading] = useState(false);
  function handleSubmit(event) {
    id = id.userId;
    event.preventDefault();
    const carFuel = event.target.carFuel.value;
    const carSize = event.target.carSize.value;
    let carKilometers = event.target.carKilometers.value;
    const motorcycleCC = event.target.motorcycleCC.value;
    let motorcycleKilometers = event.target.motorcycleKilometers.value;
    let flyingHours = event.target.flyingHours.value;
    let busKilometers = event.target.busKilometers.value;
    let tramKilometers = event.target.tramKilometers.value;
    let subwayKilometers = event.target.subwayKilometers.value;
    
    if (carKilometers === "" || carKilometers < 0) {
      carKilometers = 0;
    }
    if (motorcycleKilometers === "" || motorcycleKilometers < 0) {
      motorcycleKilometers = 0;
    }
    if (flyingHours === "" || flyingHours < 0) {
      flyingHours = 0;
    }
    if (busKilometers === "" || busKilometers < 0) {
      busKilometers = 0;
    }
    if (tramKilometers === "" || tramKilometers < 0) {
      tramKilometers = 0;
    }
    if (subwayKilometers === "" || subwayKilometers < 0) {
      subwayKilometers = 0;
    }

    setLoading(true);
    console.log("test");
    fetch(
      "http://localhost:18080/motorcycle?id=" +
        id +
        "&typemoto=" +
        motorcycleCC +
        "&kmmoto=" +
        motorcycleKilometers
    ).then((data) => {
      fetch(
        "http://localhost:18080/flight?id=" +
          id +
          "&hours=" +
          flyingHours
      ).then((data) => {
        fetch(
          "http://localhost:18080/publictransport?id=" +
            id +
            "&km=" +
            tramKilometers +
            "," +
            busKilometers +
            "," +
            subwayKilometers
        ).then((data) => {
          console.log(carKilometers)
          fetch(
            "http://localhost:18080/car?id=" +
              id +
              "&type=" +
              carSize +
              "&fuel=" +
              carFuel +
              "&km=" +
              carKilometers
          ).then((data) => {
            setLoading(false);
            onNext();
          });
        });
      });
    });
  }

  return loading ? (
    <LoadingScreen />
  ) : (
    <div className="formular">
      <form onSubmit={handleSubmit}>
        <h1>Individual (Transport) Carbon Footprint</h1>
        <div className="question-group">
          <label>Please enter details about your car usage in a year</label>
          <p>What kind of fuel does your car use?</p>
          <select name="carFuel">
            <option selected value="petrol">
              Petrol
            </option>
            <option value="diesel">Diesel</option>
            <option value="hybrid">Hybrid</option>
            <option value="electric">Electric</option>
          </select>
          <p>In what category does your car size fit best?</p>
          <select name="carSize">
            <option selected value="small">
              Small
            </option>
            <option value="medium">Medium</option>
            <option value="large">Large</option>
          </select>
          <p>Enter the number of kilometers you drive your car each month</p>
          <input type="number" name="carKilometers" placeholder="Car km" min="0" />
        </div>
        <div className="question-group">
          <label>
            Please enter details about your motorcycle usage in a year
          </label>
          <p>Select the cubic capacity of your motorcycle accordingly</p>
          <select name="motorcycleCC">
            <option selected value="small">
              Smaller than 125 cc
            </option>
            <option value="medium">Between 125 cc and 500 cc</option>
            <option value="large">Larger than 500 cc</option>
          </select>
          <p>
            Enter the number of kilometers you ride your motorcycle each month
          </p>
          <input type="number" name="motorcycleKilometers" placeholder="Motorcycle km" min="0"/>
        </div>
        <div className="question-group">
          <label>How often do you fly?</label>
          <p>Please provide the number of hours you spend on a plane yearly</p>
          <input type="number" name="flyingHours" placeholder="Flying hours" min="0" />
        </div>
        <div className="question-group">
          <label>How often do you take the bus?</label>
          <p>
            Please provide the number of kilometers that you make by bus every
            month
          </p>
          <input type="number" name="busKilometers" placeholder="Bus km" min="0"/>
        </div>
        <div className="question-group">
          <label>How often do you take the tram?</label>
          <p>
            Please provide the number of kilometers that you make by tram every
            month
          </p>
          <input type="number" name="tramKilometers" placeholder="Tram km" min="0"/>
        </div>
        <div className="question-group">
          <label>How often do you take the subway?</label>
          <p>
            Please provide the number of kilometers that you make by subway
            every month
          </p>
          <input type="number" name="subwayKilometers" placeholder="Subway km" min="0"/>
        </div>
        <button type="submit">Submit</button>
      </form>
    </div>
  );
};

export default Transportation;