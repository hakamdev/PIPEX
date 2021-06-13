RED='\033[0;31m'
GRN='\033[0;32m'
NC='\033[0m'
echo -e "${RED}+++++++++++ PIPX +++++++++++++${GRN}"
./pipex $1 "$2" "$3" $4
echo -e "CODE:" $?
echo
echo
echo -e "${RED}+++++++++++ BASH +++++++++++++"
echo -e $2 "<" $1 "|" $3 ">" $4";" "echo CODE: \$?${NC}"
# echo "=== CODE" $?