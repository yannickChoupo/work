import React, { useState, useRef, useEffect } from "react";
import { nanoid } from "nanoid";

// Components
import Todo from "./components/Todo";
import Form from "./components/Form";
import FilterButton from "./components/FilterButton";

function usePrevious(value) {
  const ref = useRef();
  useEffect(() => {
    ref.current = value;
  });
  return ref.current;
}

const FILTER_MAP = {
  All: () => true,
  Active: task => !task.completed,
  Completed: task => task.completed
};

const FILTER_NAMES = Object.keys(FILTER_MAP);

function App(props) {
  const [tasks, setTasks] = useState(props.tasks);
  const [filter, setFilter] = useState("All");

  const listHeadingRef = useRef(null);

  const prevTaskLength = usePrevious(tasks.length);


  const taskNoun = tasks.length !== 1 ? "tasks" : "task";
  const HeadingText = `${tasks.length} ${taskNoun} remaining`;

  useEffect(() => {
    if (tasks.length - prevTaskLength === -1) {
      listHeadingRef.current.focus();
    }
  }, [tasks.length, prevTaskLength]);


  // find the task in the tasks collection and updtate the completed 
  // attribute of the task in the collection
  function toggleTaskCompleted(id) {
    const updatedTasks = tasks.map(task => {
      if (id === task.id) {
        return { ...task, completed: !task.completed };
      }
      return task;
    })
    setTasks(updatedTasks);
  }

  function deleteTask(id) {
    const remainingTasks = tasks.filter(task => task.id !== id);
    setTasks(remainingTasks);
  }

  function editTask(id, newName) {
    const updatedTasks = tasks.map(task => {
      if (task.id === id) {
        return { ...task, name: newName };
      }
      return task;
    })
    setTasks(updatedTasks);
  }



  const taskList = tasks.filter(FILTER_MAP[filter]).map(task => (
    <Todo id={task.id}
      name={task.name}
      completed={task.completed}
      key={task.id}
      toggleTaskCompleted={toggleTaskCompleted}
      deleteTask={deleteTask}
      editTask={editTask}
    />
  )
  );

  const filterList = FILTER_NAMES.map(name => (
    <FilterButton key={name}
      name={name}
      isPressed={name === filter}
      setFilter={setFilter} />
  ));

  function addTask(name) {
    const newTask = { id: "todo-" + nanoid(), name: name, completed: false };
    setTasks([...tasks, newTask]);
  }



  return (
    <div className="todoapp stack-large">
      <h1>TodoMatic</h1>
      <Form addTask={addTask} />

      {/* array of button to filter the input */}
      <div className="filters btn-group stack-exception">
        {/* aria-pressed is use to tell assistive technology that the button can be
            ON or OFF  */}
        {filterList}
      </div>


      <h2 id="list-heading" tabIndex="-1" ref={listHeadingRef}>
        {HeadingText}
      </h2>
      {/* - the role attribute helps assistive technology explain what kind of element 
          a tag represents 
          - the aria-labelledby: tells assiative technolgies that we're treating our 
            list-heading as label to describe the purpose of the lisr beneath it 
      */}
      <ul
        role="list"
        className="todo-list stack-large stack-exception"
        aria-labelledby="list-heading"
      >
        {taskList}
        {/* <Todo name="eat" completed={true} id="todo-0" />
        <Todo name="sleep" completed={false} id="todo-1" />
        <Todo name="code" completed={false} id="todo-2" /> */}
      </ul>
    </div>
  );
}
export default App;
