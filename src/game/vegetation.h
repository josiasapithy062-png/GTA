// ELYRIA STORIES - Header vegetation
#ifndef VEGETATION_H
#define VEGETATION_H

typedef enum {
    OAK,
    PALM,
    PINE,
    BUSH,
    GRASS,
    CACTUS
} TreeType;

typedef struct {
    char name[32];
    TreeType type;
    float height;
    float radius;
    int country;
    float pos_x;
    float pos_y;
    int is_loaded;
} Tree;

extern Tree trees[];
extern int total_trees;

void load_trees(int country);
int check_tree_collision(float x, float y, float radius);
void destroy_tree(int index);

#endif
