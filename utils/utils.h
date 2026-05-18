#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "../models/models.h"

// ============================================================================
// 1. CÁC HÀM XỬ LÝ CHUỖI VÀ ĐỊNH DẠNG (STRING MANIPULATION)
// ============================================================================

/**
 * @brief Xóa khoảng trắng thừa ở đầu và cuối chuỗi (Trim).
 * @note Rất quan trọng vì dữ liệu CSV thực tế thường chứa khoảng trắng bẫy (ví dụ: " OPEN APP ").
 * @param str Chuỗi cần xử lý
 * @return Chuỗi đã được làm sạch
 */
std::string trim(const std::string& str);

/**
 * @brief Cắt một chuỗi lớn thành các chuỗi nhỏ dựa trên ký tự phân tách (Delimiter).
 * @note Thay vì dùng std::vector, ta dùng mảng động các std::string để lưu kết quả.
 * @param str Chuỗi thô cần cắt
 * @param delim Ký tự phân tách (ví dụ: dấu phẩy ',')
 * @param outArray Tham chiếu đến mảng động các string (sẽ được cấp phát bên trong hàm)
 * @return Số lượng phần tử (cột) tách được
 */
int splitString(const std::string& str, char delim, std::string*& outArray);


// ============================================================================
// 2. CÁC THUẬT TOÁN SẮP XẾP TỐI ƯU (EFFICIENT SORTING ALGORITHMS)
// ============================================================================

/**
 * @brief Thuật toán Quick Sort để sắp xếp mảng động các con trỏ LogRecord theo thứ tự tăng dần của timestamp.
 * @note Phục vụ in hành trình User/Resource chính xác theo tiến trình thời gian.
 * @param arr Mảng động các con trỏ LogRecord
 * @param low Chỉ số bắt đầu
 * @param high Chỉ số kết thúc
 */
void quickSortLogs(LogRecord** arr, int low, int high);

/**
 * @brief Hoán vị hai con trỏ LogRecord trong mảng.
 */
void swapLogPointers(LogRecord*& a, LogRecord*& b);


// ============================================================================
// 3. KIỂM TRA LOGIC DỮ LIỆU (VALIDATION UTILITIES)
// ============================================================================

/**
 * @brief Kiểm tra xem mã vị trí địa lý có nằm trong danh sách hợp lệ của đề bài hay không.
 * @details Các vị trí hợp lệ: US, VN, JP, KR, SG, CN, DE, FR, UK, AU, CA, IN, BR, RU, TH
 * @param loc Chuỗi mã quốc gia cần kiểm tra
 * @return true nếu hợp lệ, false nếu là dữ liệu bẩn
 */
bool isValidLocation(const std::string& loc);

/**
 * @brief Kiểm tra xem loại sự kiện có nằm trong danh sách sự kiện của hệ thống hay không.
 * @details LOGIN, LOGOUT, TOKEN_REFRESH, ACCESS, FAILED_LOGIN, OPEN_APP, DOWNLOAD, ADMIN_ACTION
 * @param event Loại sự kiện cần kiểm tra
 * @return true nếu hợp lệ, false nếu bất thường
 */
bool isValidEventType(const std::string& event);

#endif // UTILS_H