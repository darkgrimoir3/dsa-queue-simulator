#include "road.h"
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Display configuration
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define ROAD_WIDTH 180  // Width for all three lanes combined
#define LANE_WIDTH 60   // Individual lane width
#define VEHICLE_SIZE 30 // Size of vehicle representation

// Function to show lane identifiers for debugging purposes
void RenderLaneIdentifiers(SDL_Renderer *renderer)
{
    // Set text color to dark
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

    // North road (A) identifiers
    for (int laneIdx = 0; laneIdx < 3; laneIdx++)
    {
        char laneId[3] = {'A', 'L', '1' + laneIdx};
        int xPos = WINDOW_WIDTH / 2 - ROAD_WIDTH / 2 + laneIdx * LANE_WIDTH + LANE_WIDTH / 2 - 10;
        int yPos = 20;

        // Create text placeholder rectangle
        SDL_FRect textBox = {xPos, yPos, 20, 15};
        SDL_RenderFillRect(renderer, &textBox);
    }

    // East road (B) identifiers
    for (int laneIdx = 0; laneIdx < 3; laneIdx++)
    {
        int xPos = WINDOW_WIDTH - 40;
        int yPos = WINDOW_HEIGHT / 2 - ROAD_WIDTH / 2 + laneIdx * LANE_WIDTH + LANE_WIDTH / 2 - 10;

        SDL_FRect textBox = {xPos, yPos, 20, 15};
        SDL_RenderFillRect(renderer, &textBox);
    }

    // South road (C) identifiers
    for (int laneIdx = 0; laneIdx < 3; laneIdx++)
    {
        int xPos = WINDOW_WIDTH / 2 - ROAD_WIDTH / 2 + laneIdx * LANE_WIDTH + LANE_WIDTH / 2 - 10;
        int yPos = WINDOW_HEIGHT - 40;

        SDL_FRect textBox = {xPos, yPos, 20, 15};
        SDL_RenderFillRect(renderer, &textBox);
    }

    // West road (D) identifiers
    for (int laneIdx = 0; laneIdx < 3; laneIdx++)
    {
        int xPos = 20;
        int yPos = WINDOW_HEIGHT / 2 - ROAD_WIDTH / 2 + laneIdx * LANE_WIDTH + LANE_WIDTH / 2 - 10;

        SDL_FRect textBox = {xPos, yPos, 20, 15};
        SDL_RenderFillRect(renderer, &textBox);
    }
}

void RenderRoadSystem(SDL_Renderer *renderer)
{
    // Create background (darker asphalt appearance)
    SDL_SetRenderDrawColor(renderer, 40, 42, 54, 60);
    SDL_FRect backgroundArea = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &backgroundArea);

    // Road surface color (lighter asphalt)
    SDL_SetRenderDrawColor(renderer, 80, 82, 94, 255);

    // Define the four road segments
    SDL_FRect northRoad = {WINDOW_WIDTH / 2 - ROAD_WIDTH / 2, 0, ROAD_WIDTH, WINDOW_HEIGHT / 2};
    SDL_FRect southRoad = {WINDOW_WIDTH / 2 - ROAD_WIDTH / 2, WINDOW_HEIGHT / 2, ROAD_WIDTH, WINDOW_HEIGHT / 2};
    SDL_FRect eastRoad = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - ROAD_WIDTH / 2, WINDOW_WIDTH / 2, ROAD_WIDTH};
    SDL_FRect westRoad = {0, WINDOW_HEIGHT / 2 - ROAD_WIDTH / 2, WINDOW_WIDTH / 2, ROAD_WIDTH};

    // Render road surfaces
    SDL_RenderFillRect(renderer, &northRoad);
    SDL_RenderFillRect(renderer, &eastRoad);
    SDL_RenderFillRect(renderer, &southRoad);
    SDL_RenderFillRect(renderer, &westRoad);

    // Lane divider markings (bright orange)
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);

    // Dash pattern configuration
    int dashSegment = 15, dashGap = 15;

    // Vertical dividers (north-south roads)
    for (int divider = 1; divider <= 2; divider++)
    {
        int xPos = WINDOW_WIDTH / 2 - ROAD_WIDTH / 2 + divider * LANE_WIDTH;
        for (int yPos = 0; yPos < WINDOW_HEIGHT; yPos += dashSegment + dashGap)
        {
            SDL_RenderLine(renderer, xPos, yPos, xPos, yPos + dashSegment);
        }
    }

    // Horizontal dividers (east-west roads)
    for (int divider = 1; divider <= 2; divider++)
    {
        int yPos = WINDOW_HEIGHT / 2 - ROAD_WIDTH / 2 + divider * LANE_WIDTH;
        for (int xPos = 0; xPos < WINDOW_WIDTH; xPos += dashSegment + dashGap)
        {
            SDL_RenderLine(renderer, xPos, yPos, xPos + dashSegment, yPos);
        }
    }

    // Uncomment to show lane identifiers for development
    // RenderLaneIdentifiers(renderer);
}