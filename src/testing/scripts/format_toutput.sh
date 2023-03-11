sed -e '/Running/ i\'$'\n\n' \
    -e 's/test.c/test.check/' \
    -e "s/.*src/$TST\/check_files/" \
    -e 's/testing/\ttesting/' \
    -e 's/:0://' \
    -e 's/:[0-9]*:[FE]:[a-z]*:/ /g' |
awk '{  
    if (NF > 7) {
        cmd="awk /#test\\ " $2 "/{print\\ NR} " $1
        cmd | getline ln
        close(cmd)
        printf "\t%s:%s:%s %s=%s %s=%s\n", $1,ln,$2,$8,$10,$11,$13
    } else {
        printf "%s\n", $0
    }
    }
    '
# awk '{
#     if (NF > 7) {
#         cmd="awk /#test\\ " $2 "/{print\\ NR} " $1;
#         cmd | getline ln;
#         printf "\t%s:%s:%s ", $1, ln, $2;
#         for (i=8; i<=NF; i++) printf "%s ", $i;
#         printf "\n";
#         close(cmd);
#         fflush();
#     } else {
#         print $0;
#     }
#     }'
    # -e 's/check:[0-9]*:[FE]:/check /g' \
# awk -v ln='(grep -n -m 1 precision testing/check_files/sscanf_test.check)' '{sed -i"" "s/\.[0-9]\./$ln/g"}'