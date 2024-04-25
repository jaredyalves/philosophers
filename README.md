# Philosophers

*I never thought philosophy would be so deadly.*

In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.
To know more about the project, read the [subject](subject/en.subject.pdf) included.

## Requirements

Make sure you have the essentials to build C language.

* Ubuntu/Debian

```bash
sudo apt install -y build-essential
```

* Fedora/RHEL

```bash
sudo dnf groupinstall -y "C Development Tools and Libraries"
```

* Arch Linux

```bash
sudo pacman -S --noconfirm base-devel
```

* Void Linux

```bash
sudo xbps-install -Sy base-devel
```

## Build

To build the mandatory part:

```bash
cd project/philo/
make
```

## Usage

```bash
philo num_of_philos time_to_die time_to_eat time_to_sleep [times_must_eat]
```

* **num_of_philos**: The number of philosophers and also the number of forks.
* **time_to_die**: If a philosopher didn’t start eating *time_to_die* milliseconds
    since the beginning of their last meal or the beginning of the simulation, they die.
* **time_to_eat**: The time in milliseconds it takes for a philosopher to eat.
    During that time, they will need to hold two forks.
* **time_to_sleep**: The time in milliseonds a philosopher will spend sleeping.
* **num_times_to_eat (optional)**: If all philosophers have eaten at least *num_times_to_eat* times,
    the simulation stops. If not specified, the simulation stops only when a philosopher dies.

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[The Unlicense](https://choosealicense.com/licenses/unlicense/)
