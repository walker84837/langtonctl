# LangtonCtl

LangtonCtl simulates [Langton's
Ant](https://en.wikipedia.org/wiki/Langton%27s_ant), a cellular automaton. It
shows an ant moving on a grid. Complex patterns form over time.

## Features

  - **Interactive Visualization**: Start and stop the simulation using the left
    mouse button.
  - **Customizable Speed**: Adjust the simulation speed using command-line
    arguments.
  - **Resizable Window**: Set the resolution of the simulation window using a
    `WIDTHxHEIGHT` format.

## Installation

### Building from source

**Requirements**:

  - **Go**: LangtonCtl requires Go to be installed on your system. You can
    download it from [Go's official website](https://golang.org/dl/).
  - **Raylib-Go**: The project depends on the Raylib-Go library. You can install
    it via Go modules.

1.  Clone the repository:
    
    ``` bash
    $ git clone https://github.com/walker84837/langtonctl.git
    $ cd langtonctl
    ```

2.  Build the project:
    
    ``` bash
    $ make build
    ```

3.  Run the simulation:
    
    ``` bash
    $ langtonctl -s 2.0 -r 1024x768
    ```

### Arch Linux

There is a PKGBUILD at [archlinux/PKGBUILD](archlinux/PKGBUILD).

## Usage

LangtonCtl can be customized through the following command-line arguments:

  - **`-s` or `--speed`**: Set the speed of the simulation (e.g., `-s 2.0` for
    double speed).
  - **`-r` or `--resolution`**: Set the resolution of the simulation window
    (e.g., `-r 1024x768`).

### Example

To run the simulation at double speed with a window resolution of 1024x768, use:

``` bash
./bin/langtonctl -s 2.0 -r 1024x768
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

Contributions are welcome! Please fork the repository and submit a pull request.
For major changes, please open an issue to discuss what you would like to
change.

### Getting Started

1.  Fork the repository and clone it locally.
2.  Create a new branch for your changes.
3.  Make your modifications and ensure the code is well-documented.
4.  Test your changes thoroughly.
5.  Submit a pull request with a clear description of the changes.

## License

This project is licensed under the [BSD 3-Clause](LICENSE.md) License file for
details.

## Project Status

LangtonCtl is actively maintained. Future enhancements are planned, including
support for additional cellular automaton rules and custom ant behavior
configurations. Contributions and feedback are always welcome\!
