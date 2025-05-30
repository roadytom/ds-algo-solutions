import pandas as pd

# Read Excel file
file_path = 'Conservice Accounts Start_End Dates.xlsx'  # Replace with your Excel file path
df = pd.read_excel(file_path)


# Specify the column you want to read (e.g., 'Account')
account_number = 'Account #'
account_start_date = 'Account Open Date'
account_end_date = 'Account Closed Date'

df[account_start_date] = pd.to_datetime(df[account_start_date]).dt.strftime('%m/%d/%Y')
df[account_end_date] = pd.to_datetime(df[account_end_date]).dt.strftime('%m/%d/%Y')


# Print each value in the column on a separate line
for index, row in df.iterrows():
    row_account_number = "" if pd.isna(row[account_number]) else str(row[account_number]).strip()
    row_account_start_date = "" if pd.isna(row[account_start_date]) else str(row[account_start_date]).strip()
    row_account_end_date = "" if pd.isna(row[account_end_date]) else str(row[account_end_date]).strip()

    print(f"('{row_account_number}', '{row_account_start_date}', '{row_account_end_date}'),")

