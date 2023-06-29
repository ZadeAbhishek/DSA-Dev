now=$(date)
git commit -m "$1 Update on $now"
echo Commited with Message:$1
git push
echo Push TO Master
