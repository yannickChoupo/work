import React, { useState } from "react";

export default function From(props) {
    // to keep track on the input value
    const [name, setName] = useState('');

    // add a new task on submit and throught the addTask property in
    // the props object forward it to the APP level
    function handleSubmit(e) {
        e.preventDefault();
        props.addTask(name);
        // reset the input value to an empty value after adding the new value
        setName("");
    }

    // react on change in the input
    function handleChange(e) {
        setName(e.target.value);
    }
    return (
        <form onSubmit={handleSubmit}>
            <h2 className="label-wrapper">
                <label htmlFor="new-todo-input" className="label__lg">
                    What needs to be done?
                </label>
            </h2>
            <input
                type="text"
                id="new-todo-input"
                className="input input__lg"
                name="text"
                autoComplete="off"
                value={name}
                onChange={handleChange}
            />
            <button type="submit" className="btn btn__primary btn__lg">
                Add
            </button>
        </form>
    );
}