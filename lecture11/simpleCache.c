#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int data;
    int mem_addr;
} cell_t;

typedef struct hash {
    cell_t *table;
    int cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int memory_t;

memory_t *init_memory(int size) {
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
    for (int i=0; i<size; i++)
        memory[i] = rand();
    return memory;
}

cache_t* init_cache(int cache_size) {
    cache_t *cache = (cache_t *)malloc(sizeof(cache_t));
    cache->cache_size = cache_size;
    cache->table = (cell_t *)malloc(sizeof(cell_t) * cache_size);
    for (int i = 0; i < cache_size; i++) {
        cache->table[i].data = -1; // ค่าเริ่มต้นที่ไม่ได้ใช้งาน
        cache->table[i].mem_addr = -1;
    }
    return cache;
}

// ฟังก์ชันสำหรับเข้าถึงข้อมูลในแคชหรือหน่วยความจำ
void get_data(int addr, memory_t *memory, cache_t *cache) {
    int cache_index = addr % cache->cache_size;  // คำนวณ index ในแคช
    if (cache->table[cache_index].mem_addr == addr) {
        // พบในแคช
        printf("Address %d is loaded\n", addr);
    } else {
        // ไม่พบในแคช ต้องโหลดจาก memory
        if (cache->table[cache_index].mem_addr != -1) {
            // ช่องในแคชถูกใช้แล้ว
            printf("Index: %d is used\n", cache_index);
        }
        printf("Load from memory\n");
        // คัดลอกข้อมูลจาก memory ไปแคช
        cache->table[cache_index].data = memory[addr];
        cache->table[cache_index].mem_addr = addr;
    }
    // แสดงข้อมูลที่อ่านได้
    printf("Data: %d\n", cache->table[cache_index].data);
}

// ...
int main(void) {
    memory_t *memory = NULL;
    cache_t  *cache = NULL;
    int memory_size, cache_size;
    int i, n, addr;
    scanf("%d %d %d", &memory_size, &cache_size, &n); //. Memory size, cache size, number of loads
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);

    for (i=0; i<n; i++) {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}