# This is a distributed leaderboard

## Features

- [x] Distributed.
- [ ] Journaling.
- [ ] Backup & Restore.
- [ ] Data replication & on encrypted channel.
- [ ] Application Layer Auth.
- [ ] NameSpaced.

## Achitechture

    WorkerSet Nodes To contain slots of data.
    MasterSet Nodes Will hold slot & replica locations.

## Workers

    Worker Nodes will have below services.
    Primary, Replica Slot/s and a service to manage journaling.
    Primary Service would write in to Replica Channel from which the other replica slots will.
    Journaling writes would be buffered. and would be written in local storage every 5 secs
