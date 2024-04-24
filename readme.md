# CS50 Harvard

## Week 0 - Scratch
(I skimmed over this week as I felt I didn't need this practice as it's GUI based)

## Week 1 - C Language

### Installation
1. Terminal
2. 
```bash
sudo mkdir -p /usr/local/include/
clang -E -P -x c /dev/null | grep -v '^#' > /usr/local/include/stddef.h
curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
sudo apt-get install libcs50
```
