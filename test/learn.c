#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

#define MAX_PARTICLES 500
#define PI 3.14159265
#define WIDTH 800
#define HEIGHT 600

// 粒子结构体
typedef struct {
    float x, y;        // 当前位置
    float vx, vy;       // 速度
    float life;         // 生命周期
    float maxLife;      // 最大生命周期
    int color;          // 颜色
    int size;           // 粒子大小
    int isExploded;     // 是否已爆炸
} Particle;

Particle particles[MAX_PARTICLES];
int particleCount = 0;

// 初始化烟花粒子
void initParticle(Particle *p, float x, float y, int isExploded) {
    p->x = x;
    p->y = y;
    p->life = 1.0;
    p->maxLife = 1.0;
    p->isExploded = isExploded;
    p->size = rand() % 4 + 1;
    
    if (!isExploded) {
        // 上升阶段
        p->vx = 0;
        p->vy = -(rand() % 5 + 8);
        p->color = YELLOW;
    } else {
        // 爆炸阶段
        float angle = (rand() % 360) * PI / 180.0;
        float speed = (rand() % 10 + 5) / 10.0;
        p->vx = cos(angle) * speed;
        p->vy = sin(angle) * speed;
        
        // 随机颜色
        int colorChoice = rand() % 6;
        switch(colorChoice) {
            case 0: p->color = RED; break;
            case 1: p->color = GREEN; break;
            case 2: p->color = BLUE; break;
            case 3: p->color = YELLOW; break;
            case 4: p->color = MAGENTA; break;
            case 5: p->color = CYAN; break;
        }
    }
}

// 发射新烟花
void launchFirework() {
    if (particleCount < MAX_PARTICLES - 100) {
        int x = rand() % (WIDTH - 100) + 50;
        int y = HEIGHT;
        for (int i = 0; i < 1; i++) {
            initParticle(&particles[particleCount], x, y, 0);
            particleCount++;
        }
    }
}

// 更新粒子状态
void updateParticles() {
    for (int i = 0; i < particleCount; i++) {
        Particle *p = &particles[i];
        
        if (p->life <= 0) continue;
        
        // 更新位置
        p->x += p->vx;
        p->y += p->vy;
        
        // 重力效果
        if (p->isExploded) {
            p->vy += 0.05;
            p->vx *= 0.99;  // 空气阻力
        }
        
        // 减少生命周期
        p->life -= 0.008;
        
        // 如果上升粒子到达顶点，则爆炸
        if (!p->isExploded && p->vy >= -2) {
            p->isExploded = 1;
            // 创建爆炸粒子
            for (int j = 0; j < 100; j++) {
                if (particleCount < MAX_PARTICLES) {
                    initParticle(&particles[particleCount], p->x, p->y, 1);
                    particleCount++;
                }
            }
            p->life = 0;  // 原粒子消失
        }
    }
}

// 绘制粒子
void drawParticles() {
    for (int i = 0; i < particleCount; i++) {
        Particle *p = &particles[i];
        
        if (p->life <= 0) continue;
        
        // 根据生命周期计算透明度
        int alpha = (int)(p->life * 255);
        
        // 设置颜色
        setcolor(p->color);
        setfillstyle(SOLID_FILL, p->color);
        
        // 绘制粒子
        float radius = p->size * (p->life / p->maxLife);
        fillellipse((int)p->x, (int)p->y, (int)radius, (int)radius);
    }
}

// 清理死亡的粒子
void cleanupParticles() {
    int alive = 0;
    for (int i = 0; i < particleCount; i++) {
        if (particles[i].life > 0) {
            particles[alive] = particles[i];
            alive++;
        }
    }
    particleCount = alive;
}

// 绘制背景
void drawBackground() {
    setcolor(DARKGRAY);
    for (int i = 0; i < 20; i++) {
        int x = rand() % WIDTH;
        int y = rand() % 50;
        int size = rand() % 3 + 1;
        fillellipse(x, y, size, size);
    }
}

int main() {
    srand(time(NULL));
    
    // 初始化图形模式
    initwindow(WIDTH, HEIGHT, "Fireworks Display - Press ESC to Exit");
    setbkcolor(BLACK);
    cleardevice();
    
    int frames = 0;
    int launchTimer = 0;
    
    // 主循环
    while (!kbhit() || getch() != 27) {  // 按ESC退出
        cleardevice();
        
        // 定期发射新烟花
        launchTimer++;
        if (launchTimer >= 30) {  // 每30帧发射一次
            launchFirework();
            launchTimer = 0;
        }
        
        // 随机发射
        if (rand() % 50 == 0) {
            launchFirework();
        }
        
        // 更新和绘制
        updateParticles();
        drawBackground();
        drawParticles();
        cleanupParticles();
        
        // 显示帧率
        frames++;
        setcolor(WHITE);
        char fpsText[20];
        sprintf(fpsText, "Frames: %d", frames);
        outtextxy(10, 10, fpsText);
        sprintf(fpsText, "Particles: %d", particleCount);
        outtextxy(10, 30, fpsText);
        outtextxy(10, HEIGHT - 20, "Press ESC to Exit");
        
        // 控制帧率
        delay(16);  // 大约60FPS
    }
    
    closegraph();
    return 0;
}