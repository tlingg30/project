% Snake game final version
% Run the code to play. Make sure to read the guide.

clear all
clc

global level game_status highest_point attempt point_array attempt_array

% Message box showing the guide to the game
waitfor(msgbox(sprintf(['You are a snake moving around to eat apples \n' ...
    'Use the keyboard arrow to move up, down, left, right \n' ...
    'If you hit yourself or hit the black walls then you die, game over\n' ...
    'Only medium and hard level have black walls, on easy level, you are freely to move around \n' ...
    'Press esc to exit the game \n' ...
    'Press space to pause and see the guidelines again']), 'Guidelines'))

% Asking which level the user want to play in
option = questdlg('What level would you like to play?', ...
    'Choosing level', ...
    'Easy','Medium','Hard', 'Easy');
switch option
    case 'Easy'
        level = "easy";
    case 'Medium'
        level = "medium";
    case 'Hard'
        level = "hard";
end

% Some default variables at the start of the game
game_status = 1;
highest_point = 0;
attempt = 1;
point_array = [];
attempt_array = 1;

% Start the game
while game_status
    snake_game()
end

% snake_game function - main function of the game
function snake_game
global img direction key red green blue point level game_status highest_point attempt point_array attempt_array
% Creating green 40 by 40 image
red = 126* ones(40,40);
green = 200* ones(40,40);
blue = 80*ones(40,40);

% Create a specific outline for each levels
if level == "medium" || level == "hard"
    rows = 40;
    cols = 40;
    for row = 1: 40
        for col = 1: 40
            if row == 1 || row == rows || col == 1 || col == cols
                red(row, col) = 0;
                green(row, col) = 0;
                blue(row, col) = 0;
                img = cat(3, red, green, blue);
            end
        end
    end

    if level == "hard"
        wall_row = [11 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 29];
        wall_col_1 = [13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 13];
        wall_col_2 = [28 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 28];
        wall_center_row = [20 20 21 21];
        wall_center_col = [20 21 20 21];
        for i = 1: length(wall_col_2)
            red(wall_row(i), wall_col_1(i)) = 0;
            green(wall_row(i), wall_col_1(i)) = 0;
            blue(wall_row(i), wall_col_1(i)) = 0;
            red(wall_row(i), wall_col_2(i)) = 0;
            green(wall_row(i), wall_col_2(i)) = 0;
            blue(wall_row(i), wall_col_2(i)) = 0;
            img = cat(3, red, green, blue);
        end
        for j = 1: length(wall_center_col)
            red(wall_center_row(j), wall_center_col(j)) = 0;
            green(wall_center_row(j), wall_center_col(j)) = 0;
            blue(wall_center_row(j), wall_center_col(j)) = 0;
        end
    end
end

% The starting point of the snake
row_pos= [25 25 25 25];
col_pos= [23 24 25 26];
new_position(row_pos, col_pos);

% Generating apple
while true
    apple_row = randi([1,40],1);
    apple_col = randi([1,40],1);
    if red(apple_row, apple_col) == 126 ...
            && green(apple_row, apple_col) == 200 ...
            && blue(apple_row, apple_col) == 80
        red(apple_row, apple_col) = 199;
        green(apple_row, apple_col) = 55;
        blue (apple_row, apple_col) = 74;
        img = cat(3, red, green, blue);
        break
    end
end

% display the game window - Delete all the number title and menue bar of the figure window
snake_window = figure('Name','Snake Game', 'Numbertitle','off','Menubar','none');
% Set the keypressfcn to be a handle to function key_control
set(snake_window,'KeyPressFcn',@key_control);

% The starting direction and of the game
key = 'uparrow';
direction = "up";
point = 0;

while game_status
    % Checking if the user close the window figure
    if ~ishandle (snake_window)
        game_status = 0;
        delete(gcf)
        break
    else
        game_status = 1;
    end

    % Checking if the user press esc or space
    if strcmp(key, 'escape')
        option = questdlg('Please dont leave me :((', ...
            'Are you sure?', ...
            'Sorry, Im leaving','Jk. I wont leave you', 'Jk. I wont leave you');
        switch option
            case 'Sorry, Im leaving'
                game_status = 0;
                msgbox(sprintf('You exit the game! Your score is %d', point))
                delete(gcf)
                break
            case 'Jk. I wont leave you'
                game_status = 1;

        end
    elseif strcmp(key, 'space')
        waitfor(msgbox(sprintf(['You are a snake moving around to eat apples \n' ...
            'Use the keyboard arrow to move up, down, left, right \n' ...
            'If you hit yourself or hit the black walls then you die, game over\n' ...
            'Only medium and hard level have black walls, on easy level, you are freely to move around \n' ...
            'Press esc to exit the game \n' ...
            'Press space to pause and see the guidelines again']), 'Guidelines'))
    else
        game_status = 1;
    end

    % Return the key data based on the direction
    if direction == "up"
        key = 'uparrow';
    elseif direction =="down"
        key = 'downarrow';
    elseif direction == "left"
        key = 'lefarrow';
    elseif direction == "right"
        key = 'rightarrow';
    end

    % Update the length of the snake after each iteration
    len_snake = length(row_pos);
    pause(0.03)

    % clear the board after each iteration
    red = 126* ones(40,40);
    green = 200* ones(40,40);
    blue = 80*ones(40,40);

    % recreate the outline for each level after each iteration
    if level == "medium" || level == "hard"
        for row = 1: 40
            for col = 1: 40
                if row == 1 || row == rows || col == 1 || col == cols
                    red(row, col) = 0;
                    green(row, col) = 0;
                    blue(row, col) = 0;
                    img = cat(3, red, green, blue);
                end
            end
        end

        if level == "hard"
            rows = 40;
            cols = 40;
            wall_row = [11 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 29];
            wall_col_1 = [13 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 13];
            wall_col_2 = [28 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 29 28];
            wall_center_row = [20 20 21 21];
            wall_center_col = [20 21 20 21];
            for i = 1: length(wall_col_2)
                red(wall_row(i), wall_col_1(i)) = 0;
                green(wall_row(i), wall_col_1(i)) = 0;
                blue(wall_row(i), wall_col_1(i)) = 0;

                red(wall_row(i), wall_col_2(i)) = 0;
                green(wall_row(i), wall_col_2(i)) = 0;
                blue(wall_row(i), wall_col_2(i)) = 0;
                img = cat(3, red, green, blue);
            end
            for j = 1: length(wall_center_col)
                red(wall_center_row(j), wall_center_col(j)) = 0;
                green(wall_center_row(j), wall_center_col(j)) = 0;
                blue(wall_center_row(j), wall_center_col(j)) = 0;
            end
        end
    end

    % check if the snake eat the apple
    if row_pos(1) == apple_row && col_pos(1) == apple_col
        row_pos(2:len_snake+1) = row_pos(1:len_snake);
        col_pos(2:len_snake+1) = col_pos(1:len_snake);
        point = point + 1;
        % Add another apple after the snake eat the previous apple
        while true
            apple_row = randi([1,40],1);
            apple_col = randi([1,40],1);
            if red(apple_row, apple_col) == 126 ...
                    && green(apple_row, apple_col) == 200 ...
                    && blue(apple_row, apple_col) == 80
                red(apple_row, apple_col) = 199;
                green(apple_row, apple_col) = 55;
                blue (apple_row, apple_col) = 74;
                img = cat(3, red, green, blue);
                break
            end
        end
    else
        row_pos(2:len_snake) = row_pos(1:len_snake - 1);
        col_pos(2:len_snake) = col_pos(1:len_snake - 1);
        % Apple stays in the same direction
        red(apple_row, apple_col) = 199;
        green(apple_row, apple_col) = 55;
        blue (apple_row, apple_col) = 74;
        img = cat(3, red, green, blue);
    end

    % Checking if the snake touch the black walls in medium and hard level
    if level == "hard" || level == "medium"
        if direction == "right" % right
            if red(row_pos(1), col_pos(1)) == 0 && green(row_pos(1), col_pos(1)) == 0 && blue(row_pos(1), col_pos(1)) == 0
                game_status = 0;
            else
                col_pos(1) = col_pos (1) +1;
            end
        elseif direction == "down" % down
            if red(row_pos(1), col_pos(1)) == 0 && green(row_pos(1), col_pos(1)) == 0 && blue(row_pos(1), col_pos(1)) == 0
                game_status = 0;
            else
                row_pos (1) = row_pos(1)+1;
            end
        elseif direction == "left" %left
            if red(row_pos(1), col_pos(1)) == 0 && green(row_pos(1), col_pos(1)) == 0 && blue(row_pos(1), col_pos(1)) == 0
                game_status = 0;
            else
                col_pos(1) = col_pos(1) - 1;
            end
        elseif direction == "up" % up
            if red(row_pos(1), col_pos(1)) == 0 && green(row_pos(1), col_pos(1)) == 0 && blue(row_pos(1), col_pos(1)) == 0
                game_status = 0;
            else
                row_pos(1) = row_pos(1) - 1;
            end
        end

        % If the user play in easy mode, then there is no walls and the
        % user move around freely.
    else
        if direction == "right" % right
            if col_pos(1) ~= 40
                col_pos(1) = col_pos (1) +1;
            else
                col_pos(1) = 1;
            end
        elseif direction == "down" % down
            if row_pos(1) ~= 40
                row_pos (1) = row_pos(1)+1;
            else
                row_pos(1) = 1;
            end
        elseif direction == "left" %left
            if col_pos(1) ~= 1
                col_pos(1) = col_pos(1) - 1;
            else
                col_pos(1) = 40;
            end
        elseif direction == "up" % up
            if row_pos(1) ~= 1
                row_pos(1) = row_pos(1) - 1;
            else
                row_pos(1) = 40;
            end
        end
    end

    % Checking if the snake bite itself
    for i = 2: len_snake
        if row_pos(1) == row_pos(i) && col_pos(1) == col_pos(i)
            game_status = 0;
        end
    end

    % If game over -> restart the game or see performance chart
    if game_status == 0
        image = imread('gameover.jpg');
        imshow(image, "InitialMagnification", 'fit', 'Border','tight')
        if point > highest_point
            highest_point = point;
        end
        point_array = [point_array point];
        option = questdlg((sprintf('Game over! Your score is %d \n You have play %d times \n The highest score is %d \n Do you want to restart', point, attempt, highest_point)), ...
            'Restart?', ...
            'Yes','No', 'Yes');
        switch option
            case 'No'
                if attempt > 1 % only show performance chart if the user attempts 2 times or more
                    perf_answer = questdlg(sprintf('Do you want to see you performance chart?'), ...
                        'Performance chart', ...
                        'Yes','No', 'Yes');
                    switch perf_answer
                        case 'Yes'
                            game_status = 0;
                            close force all;
                            delete(gcf);
                            plot(attempt_array, point_array);
                            xticks(attempt_array);
                            yticks(0:2:360);
                            title('Performance Chart')
                            xlabel('Attempts')
                            ylabel('Points')
                            break
                        case 'No'
                            game_status = 0;
                            close force all;
                            delete(gcf);
                            break
                    end
                else
                    game_status = 0;
                    close force all;
                    delete(gcf);
                    break
                end
            case 'Yes'
                close force all;
                delete(gcf);
                game_status = 1;
                attempt = attempt+1;
                attempt_array = [attempt_array attempt];
                break
        end
    end

    % Update the position and showing the image after each iteration
    new_position(row_pos, col_pos);
    imshow(uint8(img), "InitialMagnification", 'fit', 'Border','tight')
end
end

% new_position function - function responsible for making the snake move
function new_position(row_pos, col_pos)
global red blue green img
red(row_pos(1), col_pos(1)) = 121;
green(row_pos(1), col_pos(1)) = 92;
blue (row_pos(1), col_pos(1))= 50;
for i = 2: length(row_pos)
    red(row_pos(i), col_pos(i)) = 153;
    green(row_pos(i), col_pos(i)) = 121;
    blue (row_pos(i), col_pos(i))= 80;
end
img = cat(3, red, green, blue);
end

% key_control function - control the snake via keyboard stroke
function key_control (src, event)
global key direction
key = event.Key;
if strcmp(key, 'uparrow')
    if direction ~= "down"
        direction = "up";
    end
elseif strcmp(key, 'downarrow')
    if direction ~= "up"
        direction = "down";
    end
elseif strcmp(key, 'leftarrow')
    if direction ~= "right"
        direction = "left";
    end
elseif strcmp(key, 'rightarrow')
    if direction ~= "left"
        direction = "right";
    end
end
end