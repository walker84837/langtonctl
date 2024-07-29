# langtonctl

LangtonCtl is a visual simulation of Langton's Ant, a classic example of a
cellular automaton. In this simulation, an ant moves on a grid. The ant's
behaviour creates patterns.

Langton's Ant is an algorithm that creates complex behaviour from simple rules.
You can see the simulation in a window, where you can also change the grid
resolution and ant speed. For more information about Langton's Ant, check out
[Langton's Ant on Wikipedia](https://en.wikipedia.org/wiki/Langton%27s_ant).

## Features

  - Real-time simulation of Langton's Ant.
  - Adjustable grid resolution and ant speed.
  - Toggle pause with a mouse click.
  - Simple and clean graphical output using Raylib.

## Installation

To run this project, you'll need to have [Raylib](https://www.raylib.com/)
installed. Follow these steps to get started:

1.  **Clone the repository:**
    
    ``` bash
    git clone https://github.com/walker84837/langtonctl.git
    cd langtonctl
    ```

2.  **Compile the project:**
    
    You can use the provided Makefile to compile the project. Run:
    
    ``` bash
    make
    ```
    
    This will create an executable named `langtonctl`.

## Usage

Run the executable with optional arguments to adjust the simulation parameters:

``` bash
./langtonctl -s <speed> -r <resolution>
```

  - `-s <speed>`: Sets the speed of the simulation. The default is `1.0`.
  - `-r <resolution>`: Sets the grid resolution in the format `WIDTHxHEIGHT`.
    The default is `800x800`.

### Example

To run the simulation with a speed of `2.0` and a resolution of `1024x768`, use:

``` bash
./langtonctl -s 2.0 -r 1024x768
```

## Support

For any issues or questions, please open an issue on the [GitHub
repository](https://github.com/walker84837/langtonctl/issues). For more
immediate support, you can reach out via Matrix (`@winlogon.exe:matrix.org`).

## Roadmap

Future updates may include:

  - Enhanced graphical effects and visualizations.
  - Additional configuration options for simulation parameters.

## Contributing

Contributions are welcome! Please follow these steps to contribute:

1.  Fork the repository.
2.  Create a new branch for your feature or bugfix.
3.  Commit your changes and push to your fork.
4.  Open a pull request to the main repository.

Please ensure that your code adheres to the existing style and that you have
tested your changes thoroughly.

## License

This project is licensed under the GNU General Public License v3.0 - see the
[LICENSE](LICENSE.md) file for details.

## Project Status

The development of this project is ongoing. Contributions are encouraged, and we
welcome feedback and suggestions for improvements.
