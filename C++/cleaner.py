#!/usr/bin/env python3
import os
import shutil

def find_targets(root="."):
    """
    Recursively find files without extensions and folders ending with .dSYM,
    while excluding specified paths and files.
    """
    targets = []
    # --- Define exclusion patterns ---
    # Folders containing these substrings will be skipped entirely.
    excluded_folder_patterns = ["cmake", "idea"]
    # Files with this name (case-insensitive) will be ignored.
    excluded_filenames = ["readme"]

    # os.walk is perfect for recursively walking through a directory tree.
    for dirpath, dirnames, filenames in os.walk(root, topdown=True):

        # --- 1. Exclude Directories ---
        # To prevent os.walk from going into excluded folders, we modify
        # dirnames in-place. We iterate over a copy [:] to safely modify it.
        dirnames[:] = [d for d in dirnames if not any(pattern in d.lower() for pattern in excluded_folder_patterns)]

        # --- 2. Find Target Folders ---
        # Check the remaining directories at the current level.
        for dirname in dirnames:
            if dirname.endswith(".dSYM"):
                targets.append(os.path.join(dirpath, dirname))

        # --- 3. Find Target Files ---
        # Check all files at the current level.
        for filename in filenames:
            # Skip any README files (e.g., README, readme.md, README.txt)
            if os.path.splitext(filename)[0].lower() in excluded_filenames:
                continue

            # Target condition: file has no extension.
            if "." not in filename:
                targets.append(os.path.join(dirpath, filename))

    return targets

def clean_root(root="."):
    """Finds and deletes targets after user confirmation."""
    targets = find_targets(root)

    if not targets:
        print("         ✅ No files or folders to delete.")
        return

    print("         ⚠️ The following items will be deleted:")
    for t in sorted(targets): # sorted() makes the list easier to read
        print("   ", t)

    try:
        choice = input("\nProceed with deletion? (y/N): ").strip().lower()
    except KeyboardInterrupt:
        print("\n         ❌ Aborted by user.")
        return

    if choice != "y":
        print("         ❌ Aborted.")
        return

    print("-" * 20) # Separator for clarity
    for t in sorted(targets):
        try:
            if os.path.isdir(t):
                shutil.rmtree(t)
                print(f"Deleted folder: {t}")
            elif os.path.isfile(t):
                os.remove(t)
                print(f"Deleted file: {t}")
        except OSError as e:
            print(f"Error deleting {t}: {e}")

    print("✅ Cleanup complete.")

if __name__ == "__main__":
    # Start the cleaning process from the current directory.
    clean_root(".")