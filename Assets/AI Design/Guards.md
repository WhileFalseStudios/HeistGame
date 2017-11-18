Guard AI:

Routines:
Patrol - walk to next target patrol point
    - Can transition to any other state
    - Idle - if told to by patrol point, for specified time
Idle - stand still and look cool. Either as a stationary guard, or stopping for a short time at a patrol point.
Hunt - search for the player, using more complex patrol routes.
Attack - shoot at the player, standing still. If the player moves out of sight (ie., off screen) then pursue the player.

States:
Calm
Angry
Attacking
Unconscious
Dead

Notes:
 - Guards should only be able to see the player if their cone of vision or actual model is on-screen. Easily tweaked by sight range.
 - Guards off-screen in attack state will shoot, but never hit the player if off-screen.