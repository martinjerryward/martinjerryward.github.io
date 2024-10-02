# Define the commit message
$commitMessage = "Auto commit by script powershell"

# Navigate to your repository (optional, if you're not already in the repo directory)
# Set-Location "C:\path\to\your\repo"

# Add all changes
git add .

# Commit with the fixed message
git commit -m $commitMessage

# Push changes to the 'main' branch
git push origin main

Write-Host "Changes have been pushed to the 'main' branch with the message: '$commitMessage'."
