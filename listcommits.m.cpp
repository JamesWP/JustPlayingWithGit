#include <iostream>
#include <cstdlib>

#include <git2/global.h>
#include <git2/repository.h>
#include <git2/types.h>
#include <git2/errors.h>

#define GIT_ERROR_CODE(a) do{gitError(a);}while(false)

void gitError(int errorCode) {
  if(errorCode == 0) return;

  std::cout << "listcommits error:" << std::endl;
  const git_error *e = giterr_last();
  std::cout << "Error: " << errorCode << "/" 
            << e->klass << ": " << e->message
            << std::endl;
  exit(1);
}


int main(int argc, char* argv[]) {

  git_libgit2_init();

  git_repository *repo;

  if(argc != 2) {
    std::cout << "listcommits <REPO_PATH>" << std::endl;
    return 1;
  }

  const char* repoPath = argv[1];

  GIT_ERROR_CODE(git_repository_open(&repo, repoPath));

  std::cout << "Opened repo" << std::endl;

  git_repository_free(repo);

  git_libgit2_shutdown();

  return 0;
}
