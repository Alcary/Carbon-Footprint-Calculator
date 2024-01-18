import LoadingScreen from "./LoadingScreen";
import { useState } from "react";

const Household = ({ onNext, id }) => {
    const [loading, setLoading] = useState(false);
    function handleSubmit(event) {
        id = id.userId;
        event.preventDefault();
        let homeSize = event.target.homeSize.value;
        let electricalEnergy = event.target.electricalEnergy.value;
        let naturalGas = event.target.naturalGas.value;
        let wood = event.target.wood.value;
        let publicHeatingNetwork = event.target.publicHeatingNetwork.value;
        let woodPellets = event.target.woodPellets.value;
        if (electricalEnergy === '' || electricalEnergy < 0) {
            electricalEnergy = 0;
        }
        if (naturalGas === '' || naturalGas < 0) {
            naturalGas = 0;
        }
        if (wood === '' || wood < 0) {
            wood = 0;
        }
        if (publicHeatingNetwork === '' || publicHeatingNetwork < 0) {
            publicHeatingNetwork = 0;
        }
        if (woodPellets === '' || woodPellets < 0) {
            woodPellets = 0;
        }
        setLoading(true);
        fetch("http://localhost:18080/house?id="+id+"&typehouse="+homeSize+"&cons="+electricalEnergy+","+naturalGas+","+wood+","+publicHeatingNetwork+","+woodPellets)
        .then(data => {
            setLoading(false);
            onNext();
        });
    }

    return (
        loading ? (<LoadingScreen />) : (
        <div className="formular">
            <form onSubmit={handleSubmit}>
                <h1>Household Carbon Footprint</h1>
                <div className='question-group'>
                    <label>Please provide information about your household consumptions</label>
                    <p>How big is your home?</p>
                    <select name="homeSize"  >
                        <option selected value="small">Between 20 and 70 square meters</option>
                        <option value="medium">Between 70 and 100 square meters</option>
                        <option value="large">Over 100 square meters</option>
                    </select>
                    <p>Tell us how much energy you use based on these categories</p>
                    <p>Electrical energy (in kWh)</p>
                    <input type='number' name='electricalEnergy' placeholder='kWh per month' min="0"/>
                    <p>Natural gas</p>
                    <input type='number' name='naturalGas' placeholder='kWh per month' min="0"/>
                    <p>Wood</p>
                    <input type='number' name='wood' placeholder='kWh per month' min="0"/>
                    <p>Public heating network</p>
                    <input type='number' name='publicHeatingNetwork' placeholder='kWh per month' min="0"/>
                    <p>Wood pellets</p>
                    <input type='number' name='woodPellets' placeholder='kWh per month' min="0"/>
                </div>
                <button type="submit">Submit</button>
            </form>
        </div>
        )
    );
};

export default Household;